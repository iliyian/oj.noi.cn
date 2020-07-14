from random import randint as rd
maxn, maxop = 9, 20

T = rd(0, maxop)

for i in range(0, T):
    if rd(0, 1) & 1:
        op = '+'
    else:
        op = '-'
    print("%c " % (op), end = "")
for i in range(0, T + 1):
    print("%d " % (rd(0, maxn)), end = "")