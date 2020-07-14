from random import randint as rd
maxn, maxm, maxk = 3000, 20000, 100000

n, m, k = rd(1, maxn), rd(0, maxm), rd(0, maxk)
print("%d %d %d" % (n, m, k))

for i in range(0, m):
    a, b = rd(1, n), rd(1, n)
    print("%d %d" % (a, b))
for i in range(0, k):
    a, b, c = rd(1, n), rd(1, n), rd(1, n)
    print("%d %d %d" % (a, b, c))