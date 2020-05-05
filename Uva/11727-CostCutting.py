import sys

T = int(input())

for t in range(T):
    a, b, c = [int(x) for x in input().split()]

    if a < b < c or c < b < a:
        print("Case " + str(t + 1) + ": " + str(b))
    elif b < a < c or c < a < b:
        print("Case " + str(t + 1) + ": " + str(a))
    else:
        print("Case " + str(t + 1) + ": " + str(c))
