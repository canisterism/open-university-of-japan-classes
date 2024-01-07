def gcd(a,b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

print(gcd(2361, 21249))
print(gcd(6957, 16233))
print(gcd(7870, 19675))
print(gcd(8503, 13141))
print(gcd(11805, 16527))
