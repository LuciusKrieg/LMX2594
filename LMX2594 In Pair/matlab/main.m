clear; clc; format long g;

Fosc1     =   100 * 10^6;
DeathZone =     5 * 10^6;
Fout1Min  =    80 * 10^6;
Fout1Max  =   120 * 10^6;
Fout2Min  =   100 * 10^6;
Fout2Max  = 12000 * 10^6;
FvcoMin   =  7500 * 10^6;
FvcoMax   = 15000 * 10^6;
ChannelDividers = [1, 2, 4, 6, 8, 12, 16, 24, 32, 48, 64, 72, 96, 128, 192, 256, 384, 512, 768];

Fvco1Bands = [0; 0];
for i = 0 : (FvcoMax - FvcoMin) / Fosc1 - 1
    Fvco1Bands(1, i + 1) = (FvcoMin + Fosc1 * (i + 0)) + DeathZone;
    Fvco1Bands(2, i + 1) = (FvcoMin + Fosc1 * (i + 1)) - DeathZone;
end

i = 1;
Fout1Bands = [0; 0; 0];
for ChannelDivider = ChannelDividers
    for Fvco1Band = Fvco1Bands
        if (Fvco1Band(2) <= 11500 * 10^6) || (ChannelDivider <= 6)
            Fout1Bands(1, i) = ChannelDivider;
            Fout1Bands(2, i) = Fvco1Band(1) / ChannelDivider;
            Fout1Bands(3, i) = Fvco1Band(2) / ChannelDivider;
            i = i + 1;
        end
    end
end

for i = length(Fout1Bands) : -1 : 1
    if Fout1Bands(2, i) < Fout1Min || Fout1Bands(3, i) > Fout1Max ...  
    || Fout1Bands(2, i) ~= round(Fout1Bands(2, i)) || Fout1Bands(3, i) ~= round(Fout1Bands(3, i))
        Fout1Bands(:, i) = [];
    end
end

ND1Old = 0;
Fout2Old = Fout2Min;
for Fout2 = Fout2Min : Fout2Max
    CD2 = ChannelDividerForFout(Fout2);
    Fvco2 = Fout2 * CD2;
    ND2 = round(Fvco2 * (12075858607/1000000000000000000));
    Fosc2 = Fvco2 / ND2;
    Fout1 = Fosc2;
	CD1 = 96;
    Fvco1 = Fout1 * CD1;
    ND1 = Fvco1 / Fosc1;
    NDN1 = floor(ND1);
    NDDEN1 = 0xFFFFFFFF;
    NDNUM1 = (ND1 - NDN1) * NDDEN1;
    
    disp( Fout2 + "    " + (((Fosc1*(NDN1+NDNUM1/NDDEN1)/CD1)*ND2/CD2) - Fout2) );
    
end