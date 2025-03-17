P, k = map(int, input().strip().split())

arr = [1 for _ in range(k+10)]

for i in range(2, k+1):
    if arr[i] == 0: continue
    for j in range(i, k+2, i):
        arr[j] = 0
    if P % i == 0:
        print("BAD", i)
        exit(0)

print("GOOD")