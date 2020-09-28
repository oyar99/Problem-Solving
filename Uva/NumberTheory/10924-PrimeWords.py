import sys

def isPrime(n):
    if n <= 2:
        return True

    if n%2 == 0:
        return False
    
    for i in range(3, int(n ** 0.5) + 1, 2):
        if n%i == 0:
            return False

    return True

for line in sys.stdin:
    s = str(line)
    s = s.strip()
    
    alphabet = {}

    lowercase = "abcdefghijklmnopqrstuvwxyz"
    uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

    count = 1
    for c in lowercase:
        alphabet[c] = count
        count = count + 1

    for c in uppercase:
        alphabet[c] = count
        count = count + 1

    val = 0
    for c in s:
        val = val + alphabet[c]
    
    if isPrime(val):
        print("It is a prime word.")
    else:
        print("It is not a prime word.")
