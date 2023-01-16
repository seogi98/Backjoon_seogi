from collections import deque
R,C = map(int,input().split());
mp = []
dx = [1,0,-1,0]
dy = [0,1,0,-1]
TotalSheep = 0
TotalWolf = 0
vst = [[False for i in range(C)] for j in range(R)]
for i in range(R):
    line = input()   
    for j in range(C):
        if(line[j] == 'o'):
             TotalSheep = TotalSheep+1
        if(line[j] == 'v'):
             TotalWolf = TotalWolf+1
    mp.append(line)
for i in range(R):
    for j in range(C):
        if(vst[i][j] or mp[i][j] == '#'):
            continue
        # y,x,양,늑대
        q = deque()
        vst[i][j] = True;
        sheep = 0
        wolf = 0
        if(mp[i][j] == 'o'):
            sheep = sheep+1
        if(mp[i][j] == 'v'):
            wolf = wolf+1
        q.append([i,j])
        while q:
            cur = q.popleft()
            y = cur[0]
            x = cur[1]
            for k in range(4):
                nx = x+dx[k]
                ny = y+dy[k]
                if(nx < 0 or nx >= C or ny < 0 or ny >= R):
                    continue
                if(mp[ny][nx] == '#'):
                    continue
                if(vst[ny][nx] == True):
                    continue;
                if(mp[ny][nx] == 'o'):
                    sheep = sheep+1
                if(mp[ny][nx] == 'v'):
                    wolf = wolf+1 
                vst[ny][nx] = True
                q.append([ny,nx])
        if(sheep <= wolf):
            TotalSheep = TotalSheep-sheep
        else:
            TotalWolf = TotalWolf-wolf
print(TotalSheep,TotalWolf)
    


                