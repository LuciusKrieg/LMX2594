function ChannelDivider = ChannelDividerForFout(Fout)
    if Fout >= 7500000000
        ChannelDivider = 1;
    else
        if Fout >= 3750000000
            ChannelDivider = 2;
        else
            if Fout >= 1875000000
                ChannelDivider = 4;
            else
                if Fout >= 1250000000
                    ChannelDivider = 6;
                else
                    if Fout >= 937500000
                        ChannelDivider = 8;
                    else
						if Fout >= 625000000
							ChannelDivider = 12;
						else
							if Fout >= 468750000
								ChannelDivider = 16;
							else
								if Fout >= 312500000
									ChannelDivider = 24;
								else
									if Fout >= 234375000
										ChannelDivider = 32;
									else
										if Fout >= 156250000
											ChannelDivider = 48;
										else
											if Fout >= 117187500
												ChannelDivider = 64;
                                            else
                                                if Fout >= 78125000
                                                    ChannelDivider = 96;
                                                else
                                                    if Fout >= 58593750
                                                        ChannelDivider = 128;
                                                    else
                                                        if Fout >= 39062500
                                                            ChannelDivider = 192;
                                                        else
                                                            if Fout >= 29296875
                                                                ChannelDivider = 256;
                                                            else
                                                                if Fout >= 19531250
                                                                    ChannelDivider = 384;
                                                                else
                                                                    if Fout >= 9765625
                                                                        ChannelDivider = 768;
                                                                    else
                                                                        ChannelDivider = 0;
                                                                    end
                                                                end
                                                            end
                                                        end
                                                    end
                                                end
											end
										end
									end
								end
							end
						end
                    end
                end
            end
        end
    end
end