from random import randint
maxn, maxk = 100, 1000

n, k = randint(1, maxn), randint(1, maxk)
print("%d %d" % (n, k))
for i in range(1, k):
    a, b = randint(1, n), randint(1, n)
    print("%d %d" % (a, b))