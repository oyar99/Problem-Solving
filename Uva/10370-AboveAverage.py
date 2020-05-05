import sys

T = int(input())

for t in range(T):

    n,*A= map(int, input().split())

    avg = 0
    for x in A:
        avg = avg + x
    avg = avg / n
    
    count = 0
    for x in A:
        if x > avg:
            count = count + 1
    
    ans = count / n
    ans = ans * 100
    print("%.3f%%" % ans)
