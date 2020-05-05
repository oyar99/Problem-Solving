import sys

for line in sys.stdin:
    n, a = map(int, line.split())

    ans = 0
    for i in range(n+1):
        ans = ans + i * pow(a, i)
    print(ans)
