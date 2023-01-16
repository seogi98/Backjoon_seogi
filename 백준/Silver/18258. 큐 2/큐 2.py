import sys
from collections import deque
n = int (sys.stdin.readline())
q =  deque()
for i in range(n):
    S = list(sys.stdin.readline().split())
    if(S[0] == "push"):
        q.append(S[1])
        continue;
    if(S[0] == "pop"):
        if q:
            print(q.popleft())
        else :
            print(-1)
        continue;
    if(S[0] == "size"):
        print(len(q))
        continue;
    if(S[0] == "empty"):
        if q:
            print(0)
        else :
            print(1)
        continue;
    if(S[0] == "front"):
        if not q:
            print(-1)
            continue
        front = q.popleft()
        q.appendleft(front)
        print(front)
        continue;
    if(S[0] == "back"):
        if not q:
            print(-1)
            continue
        back = q.pop()
        q.append(back)
        print(back)
        continue;
    
 