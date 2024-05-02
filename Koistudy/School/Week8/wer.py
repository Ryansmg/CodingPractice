h, w = map(int, input().split())
n = int(input())
asdf = [0 for _ in range(w+1)]
m = [asdf.copy() for _ in range(h+1)]
for _ in range(n):
    a, b, c, d = map(int, input().split())
    if b==1:
        for j in range(c, c+a):
            if j>h:
                break
            m[j][d] = 1
    else:
        for j in range(d, d+a):
            if j>w:
                break
            m[c][j] = 1
for i in range(1, h+1):
    for j in range(1, w+1):
        print(m[i][j], end=' ')
    print()