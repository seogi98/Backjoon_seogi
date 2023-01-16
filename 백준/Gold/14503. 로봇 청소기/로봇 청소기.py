from dataclasses import dataclass

N,M = map(int,input().split())
mp = []
y,x,d = map(int,input().split())
dx = [0,1,0,-1]
dy = [-1,0,1,0]

for i in range(N):
    line = input().split()
    mp.append(line)

@dataclass
class Robot:
    y : int = 0
    x : int = 0
    d : int = 0

def main():
    robot = Robot(y= y,x= x,d= d)
    Answer = 0
    while True:
        cur = Robot(y = robot.y,x = robot.x,d = robot.d)
        go = False
        # 현재 위치 청소
        if mp[cur.y][cur.x] == '0':
            mp[cur.y][cur.x] = '2'
            Answer = Answer+1
        for i in range(cur.d,cur.d+4):
            nxDir = i%4
            ny = cur.y+dy[nxDir]
            nx = cur.x+dx[nxDir]
            if ny < 0 or ny >= N or nx < 0 or nx >= M :
                continue
            # 갈수있는 곳이 있으면 이동
            if mp[ny][nx] == '0':
                robot = Robot(y = ny,x = nx,d = nxDir)
                go = True
                continue
        # 이동 했을경우
        if go:
            continue
        # 아래 이동
        downDir = (cur.d + 2)%4
        down = Robot(y = cur.y+dy[downDir],x = cur.x+dx[downDir],d = cur.d)
        if down.y < 0 or down.y >= N or down.x < 0 or down.x >= M or mp[down.y][down.x] == '1':
            break
        else:
            robot = down
    print(Answer)

main()






