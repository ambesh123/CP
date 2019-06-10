import math

MAXN = 1000001

ld = [1]*MAXN

def sieve():
    lim = int(math.sqrt(MAXN))
    for i in range(MAXN):
        ld[i] = i
    for i in range(2,lim):
        if ld[i] == i:
            j = i
            while j < MAXN:
                if ld[j]==j :
                    ld[j] = i
                j+= i

def prime_factors(n):
    ret = []
    while n != 1:
        ret.append(ld[n])
        n = int(n/ld[n])
    return ret

sieve()

t = int(input("How many numbers ? "))
while t > 0 :
    n = int(input("Input a number (max 1e+6) : "))
    print("It's Factors are :")
    fac = prime_factors(n)
    for i in fac:
        print(i)
    t-=1

input("done")
