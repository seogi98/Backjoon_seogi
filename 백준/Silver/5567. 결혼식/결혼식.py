n= int(input())
m = int(input())
E = [[] for _ in range(n+1)]
vst = [5 for _ in range(n+1)]
for i in range(m):
    node1, node2 = map(int,input().split())
    E[node1].append(node2)
    E[node2].append(node1)
def dfs(cur,num):
    if(vst[cur]<=num or num == 3):
        return
    vst[cur] = num
    for nx in E[cur]:
        dfs(nx,num+1)
    return 
dfs(1,0)
answer = 0
for i in range(2,n+1):
    if(vst[i]!=5):
        answer += 1
print(answer)
