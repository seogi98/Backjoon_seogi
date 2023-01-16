N = int(input())
result = 1
ans = 0
for i in range(1,N+1):
    result = result * i
result = str(result)
size  = len(result)
for i in range(1,size+1):
    if(result[size-i] != '0'):
        break
    ans += 1
print(ans)
