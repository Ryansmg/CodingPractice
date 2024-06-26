import random, sys
sys.setrecursionlimit(10**9)
class PollardRho:
    def gcd(self, a:int, b:int)->int:
        if a<b: a,b=b,a
        while b != 0:
            a, b = b, a % b
        return a

    def rand(self)->int:
        return random.randint(0, 9223372036854775807)

    def POW(self, a:int, b:int, mod:int)->int:
        a %= mod
        ans = 1
        while b != 0:
            if b % 2 == 1: ans = ans * a % mod
            b //= 2
            a = a * a % mod
        return ans

    def _isPrime(self, n:int, a:int)->bool:
        if a%n==0: return True
        d = n-1
        while True:
            temp = self.POW(a, d, n)
            if temp == n-1: return True
            if d%2==1: return temp==1 or temp==n-1
            d //= 2

    base = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41]
    def isPrime(self, n:int)->bool:
        if n <= 1: return False
        for a in self.base:
            if not self._isPrime(n, a):
                return False
        return True

    def factorize(self, n:int)->int:
        if n<2: raise ArithmeticError
        if n%2==0: return 2
        if self.isPrime(n): return n
        x = self.rand() % (n-2) + 2
        y = x
        c = self.rand() % 10 + 1
        g = 1
        while g == 1:
            x = (x * x % n + c) % n
            y = (y * y % n + c) % n
            y = (y * y % n + c) % n
            g = self.gcd(x - y if x-y>0 else y - x, n)
            if g == n : return self.factorize(n);
        if self.isPrime(g): return g
        else: return self.factorize(g)

aa, bb = map(int, input().split())
A: int = aa
p: PollardRho = PollardRho()
minF: int = 999223372036854775807
minFCnt:int = 0
s = set()
while True:
    if A==1: break
    t:int = p.factorize(A)
    s.add(t)
    A //= t
l = list(reversed(sorted(list(s))))

for i in l:
    if aa*i<=bb:
        print(aa*i)
        exit(0)
    while aa%i==0:
        aa//=i
    aa*=i
print(-1)
