#code
T=int(input())
while T>0:
    N=int(input())
    fac=1
    while N>0:
        fac=fac*N
        N=N-1
    T=T-1
    print(fac)