import random as rd
n = int(input())
f1 = open("C:\\Users\\ryans\\Desktop\\Coding\\z.etc\\school\\rand1.txt", "w")
f2 = open("C:\\Users\\ryans\\Desktop\\Coding\\z.etc\\school\\rand2.txt", "w")
for i in range(n):
    f1.write(str(rd.randrange(101)) + "\n")
    f2.write(str(rd.randrange(101)) + "\n")
f1.close()
f2.close()



n = int(input())
f1 = open("C:\\Users\\ryans\\Desktop\\Coding\\z.etc\\school\\rand1.txt", "r")
f2 = open("C:\\Users\\ryans\\Desktop\\Coding\\z.etc\\school\\rand2.txt", "r")
f3 = open("C:\\Users\\ryans\\Desktop\\Coding\\z.etc\\school\\min.txt", "w")
f4 = open("C:\\Users\\ryans\\Desktop\\Coding\\z.etc\\school\\max.txt", "w")

for i in range(n):
    a = int(f1.readline())
    b = int(f2.readline())
    if a > b:
        a, b = b, a
    f3.write(str(a) + "\n")
    f4.write(str(b) + "\n")
f1.close()
f2.close()
f3.close()
f4.close()



n = int(input())

class PollardRho:
    def gcd(self, a:int, b:int)->int:
        if a<b: a,b=b,a
        while b != 0:
            a, b = b, a % b
        return a

    def rand(self)->int:
        return rd.randint(0, 9223372036854775807)

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
p: PollardRho = PollardRho()

f1 = open("C:\\Users\\ryans\\Desktop\\Coding\\z.etc\\school\\prime.txt", "w")
for i in range(n+1):
    if p.isPrime(i):
        f1.write(str(i)+"\n")
f1.close()
