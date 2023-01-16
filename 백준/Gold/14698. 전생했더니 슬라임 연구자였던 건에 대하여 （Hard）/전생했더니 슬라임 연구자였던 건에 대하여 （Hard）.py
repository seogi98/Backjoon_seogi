import heapq
import sys
input = sys.stdin.readline
T = int(input())
arr = []
for test in range(T):
    N = int(input())
    arr = list(map(int,input().split()))
    heapq.heapify(arr)
    ans = 1
    while len(list(arr)) > 1:
        node1 = heapq.heappop(arr)
        node2 = heapq.heappop(arr)
        heapq.heappush(arr,node1*node2)
        ans = (ans * (node1 * node2))%1000000007
    print(ans)