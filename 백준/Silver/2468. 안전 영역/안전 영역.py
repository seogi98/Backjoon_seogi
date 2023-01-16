import sys
sys.setrecursionlimit(100000)
def dfs(x, y, H,vst):
    if(vst[y][x]==1):
        return
    vst[y][x] = 1
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if(nx < 0 or nx >= n or ny < 0 or ny >= n):
            continue
        if(vst[ny][nx]==1):
            continue
        if(H >= int(mp[ny][nx])):
            continue
        dfs(nx, ny, H,vst)

dx = [1, 0, -1, 0]
dy = [0, -1, 0, 1]
n = int(input())
mp = [[0 for col in range(n)] for row in range(n)]
for i in range(n):
    mp[i] = sys.stdin.readline().rsplit()
mx = 0
for i in range(101):
    H = i
    cur = 0
    vst = [[0 for col in range(n)] for row in range(n)]
    for j in range(n):
        for k in range(n):
            if(vst[j][k]==1):
                continue
            if(H >= int(mp[j][k])):
                continue
            cur += 1
            dfs(k, j, i,vst)
    mx = max(mx, cur)
print(mx)
