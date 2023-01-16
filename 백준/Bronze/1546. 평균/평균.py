import sys
def man(score,max):
    return score/max*100

n = int(input())
arr = list(map(int,sys.stdin.readline().split()))
mx = max(arr)
b = []
for  i in range(n):
    b.append(man(arr[i],mx))
print(sum(b)/n)


