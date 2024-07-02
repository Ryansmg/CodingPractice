import sys

# 15824.

div = 1000000007
def pow(a:int, b:int) -> int:
    if b==1:
        return a%div
    if b==0:
        return 1
    c = pow(a, b//2)
    if b%2==0:
        return c*c%div
    return c*c*a%div

len = int(sys.stdin.readline())
a = sorted(list(map(int, sys.stdin.readline().split())))
ans = 0
for i in range(1, len+1):
    ans -= a[i-1] * (pow(2, len-i) - pow(2, i-1))
    ans %= div

sys.stdout.write(str(ans%div))