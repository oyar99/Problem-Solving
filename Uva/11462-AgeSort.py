import sys

while True:
    n = int(input())

    if n == 0:
        break

    A = []
    
    for x in input().split():
        A.append(int(x))

    C = [0] * 100

    for x in A:
        C[x] = C[x] + 1

    L = []

    for i in range(100):
        for j in range(C[i]):
            L.append(i)
    

    for i in range(n):
        if i != n - 1:
            print(str(L[i]) + " ", end="")
        else:
            print(str(L[i]))

    
