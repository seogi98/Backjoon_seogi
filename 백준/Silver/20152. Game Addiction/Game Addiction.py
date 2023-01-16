dp = [[0]* 50 for i in range(31)]
N,M= (input().split())
N = int(N)
M = int(M)
mn = min(N,M)
mx = max(N,M)
dp[mn][mn] = 1
for i in range(mx+1):
    for j in range(mx+1):
        if i == mn and j == mn:
            continue
        if i>j:
            continue
        dp[i][j] = dp[i-1][j] + dp[i][j-1]
print(dp[mx][mx])