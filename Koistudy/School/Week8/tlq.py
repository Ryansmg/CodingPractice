d = []
for _ in range(19):
    d.append(list(map(int, input().split())))

n = int(input())
for i in range(n) :
    x,y=map(int,input().split())
    x-=1
    y-=1
    for j in range(0, 19) :
        if d[j][y]==0 :
            d[j][y]=1
        else :
            d[j][y]=0
        if d[x][j]==0 :
            d[x][j]=1
        else :
            d[x][j]=0
for list in d:
    for i in list:
        print(i, end=' ')
    print()