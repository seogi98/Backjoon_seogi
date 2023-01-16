import sys
a = int(input())
b = int(input())
c = int(input())
result = str(a*b*c)
ans = [0 for i in range(11)]
for i in range(len(result)):
    ans[int(result[i])]+=1
for i in range(10):
    print(ans[i])