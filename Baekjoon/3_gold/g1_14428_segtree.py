import sys

# 14428. 수열과 쿼리 16
# #segtree

#value, index로 사용
class pair:
    def __init__(self, x, y):
        self.a = x
        self.b = y

max_pair = pair(100000000000, -1)

def minPair(pair1: pair, pair2: pair) -> pair:
    if pair1.a < pair2.a:
        return pair1
    elif pair1.a > pair2.a:
        return pair2
    else:
        temp = min(pair1.b, pair2.b)
        return pair(pair1.a, temp)

#left, right: query 범위 / start, end: 현재 탐색 범위
def query(tree: list[pair], node, start, end, left, right) -> pair:
    if right < start or end < left:
        return max_pair
    if left <= start and end <= right:
        return tree[node]
    pair1 = query(tree, node*2, start, (start+end)//2, left, right)
    pair2 = query(tree, node*2+1, (start+end)//2+1, end, left, right)
    return minPair(pair1, pair2)
    
def update(tree: list[pair], node, start, end, target, val):
    if target < start or end < target:
        return
    elif start == end:
        tree[node].a = val
    else:
        update(tree, node*2, start, (start+end)//2, target, val)
        update(tree, node*2+1, (start+end)//2 + 1, end, target, val)
        tree[node] = minPair(tree[node*2], tree[node*2+1])

def init(aa:list[int], tree:list[pair], node, start, end):
    if(start==end):
        tree[node] = pair(aa[start-1], start)
    else:
        init(aa, tree, node*2, start, (start+end)//2)
        init(aa, tree, node*2+1, (start+end)//2+1, end)
        tree[node] = minPair(tree[node*2], tree[node*2+1])

n = int(sys.stdin.readline())
a = [int(i) for i in sys.stdin.readline().split()]
tree = [pair(0, 0) for _ in range(4*n)]
init(a, tree, 1, 1, n)
m = int(sys.stdin.readline())
for _ in range(m):
    d, b, c = (int(i) for i in sys.stdin.readline().split())
    if d==1:
        update(tree, 1, 1, n, b, c)
    else:
        sys.stdout.write(str(query(tree, 1, 1, n, b, c).b) + '\n')
