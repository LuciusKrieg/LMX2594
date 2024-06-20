import re

f = open('register map.txt', 'r', encoding = 'utf-8')

for l in f:
    l = l.removesuffix('\n').split(' ')
    while '' in l:
        l.remove('')

    print('const paramdata_t LMX2594_' + l[3] + ' = { ', end = '') 

    for i in range(0, 3):
        if l[i] != '-':
            l[i] = re.split('\:|\[', l[i].removeprefix('R').removesuffix(']'))
            if len(l[i]) == 2:
                l[i] = l[i] + [l[i][1]]
            regnumber = l[i][0]
            shift     = l[i][2]
            width     = str(int(l[i][1]) - int(l[i][2]) + 1)
            print('.data[' + str(i) + '].regnumber = ' + regnumber, end = ', ')
            print('.data[' + str(i) + '].shift = '     + shift,     end = ', ')
            print('.data[' + str(i) + '].width = '     + width,     end = ', ')

    print('};')


