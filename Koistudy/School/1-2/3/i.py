n = int(input())
if n % 2 == 0 or n % 5 == 0:
    print(-1)
    exit(0)

import sys

i = 1
while True:
    sys.stdout.write(str(1))
    if i % n == 0:
        exit(0)
    i = i * 10 + 1
    i %= n
