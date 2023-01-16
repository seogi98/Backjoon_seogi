import sys
sys.setrecursionlimit(100000)
E = [[] for i in range(200001)]
N,M = map(int,sys.stdin.readline().rstrip().split())
vst = [False for i in range(200001)]
for i in range(M):
    node1,node2 = map(int,sys.stdin.readline().rstrip().split())
    E[node2].append(node1)
X = int(input())
sum = 0
def dfs(cur):
    global sum
    for nx in E[cur]:
        if(vst[nx]):
            continue
        vst[nx] = True
        sum+=1
        dfs(nx)
dfs(X)
print(sum)
