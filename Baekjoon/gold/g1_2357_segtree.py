import sys

# 2357. 최솟값과 최댓값
# #segtree

# a:초기값, start, end:탐색 범위
def init_max(a, tree, node, start, end):
    if(start == end):
        tree[node] = a[start-1]
    else:
        init_max(a, tree, node*2, start, (start+end)//2)
        init_max(a, tree, node*2+1, (start+end)//2+1, end)
        tree[node] = max(tree[node*2], tree[node*2+1])

def update_max(tree, node, start, end, target, value):
    if target < start or end < target:
        return
    elif start == end:
        tree[node] = value
    else:
        update_max(tree, node*2, start, (start+end)//2, target, value)
        update_max(tree, node*2+1, (start+end)//2 + 1, end, target, value)
        tree[node] = max(tree[node*2], tree[node*2+1])

#left, right : 쿼리 범위, start, end: 현재 탐색 범위
def query_max(tree, node, start, end, left, right):
    if right < start or end < left:
        return -1
    elif left <= start and end <= right:
        return tree[node]
    else:
        return max(query_max(tree, node*2, start, (start+end)//2, left, right),
                   query_max(tree, node*2+1, (start+end)//2+1, end, left, right)
)
    
def init_min(a, tree, node, start, end):
    if(start == end):
        tree[node] = a[start-1]
    else:
        init_min(a, tree, node*2, start, (start+end)//2)
        init_min(a, tree, node*2+1, (start+end)//2+1, end)
        tree[node] = min(tree[node*2], tree[node*2+1])

def query_min(tree, node, start, end, left, right):
    if right < start or end < left:
        return 2147000000
    elif left <= start and end <= right:
        return tree[node]
    else:
        return min(query_min(tree, node*2, start, (start+end)//2, left, right),
                   query_min(tree, node*2+1, (start+end)//2+1, end, left, right)
)
    
n, m = tuple(int(i) for i in sys.stdin.readline().split())
a = []
for _ in range(n):
    a.append(int(sys.stdin.readline()))
tree_max = [0 for _ in range(4*n)]
tree_min = [0 for _ in range(4*n)]
init_max(a, tree_max, 1, 1, n)
init_min(a, tree_min, 1, 1, n)

for _ in range(m):
    x, y = tuple(int(i) for i in sys.stdin.readline().split())
    sys.stdout.write("{} {}\n".format(query_min(tree_min, 1, 1, n, x, y), query_max(tree_max, 1, 1, n, x, y)))
