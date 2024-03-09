import sys

# 2243. 사탕상자
# #segtree #binary_search

def query(tree, node, start, end, val):
    if start == end:
        return start
    if tree[node*2] >= val:
        return query(tree, node*2, start, (start+end)//2, val)
    else:
        return query(tree, node*2+1, (start+end)//2+1, end, val - tree[node*2])
    
def update(tree, node, start, end, target, diff):
    if target < start or end < target:
        return
    elif start == end:
        tree[node] += diff
        if tree[node] < 0:
            raise ValueError
    else:
        update(tree, node*2, start, (start+end)//2, target, diff)
        update(tree, node*2+1, (start+end)//2 + 1, end, target, diff)
        tree[node] = tree[node*2] + tree[node*2+1]

n = int(sys.stdin.readline())
tree = [0 for _ in range(4000010)]
for _ in range(n):
    req = tuple(int(i) for i in sys.stdin.readline().split())
    if req[0] == 1:
        ans = query(tree, 1, 1, 1000000, req[1])
        update(tree, 1, 1, 1000000, ans, -1)
        sys.stdout.write(str(ans)+'\n')
    else:
        update(tree, 1, 1, 1000000, req[1], req[2])
