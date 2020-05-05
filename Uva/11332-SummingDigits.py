import sys

for line in sys.stdin:
    n = line.split()[0]

    if n == '0':
        break

    while len(n) > 1:
        l = [int(x) for x in n]
        
        s = 0
        for x in l:
            s = s + x
        n = str(s)
    
    print(n)
