import java.util.*;

public class Main {
    static final int MAX = 21;
    static final int INF = 1999999999;
    static int [][] mp = new int[MAX][MAX];
    static final int []dx = {1,0,-1,0};
    static final int []dy = {0,1,0,-1};
    static int answer=0;
    public static void main(String[] args)
    {
        final int MAX = 21;
        int []dx = {1,0,-1,0};
        int []dy = {0,-1,0,1};
        int ans = 0;
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        // 어미 상어
        Shark babyShark = null;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                mp[i][j] = sc.nextInt();
                if(mp[i][j] == 9){
                    babyShark = new Shark(i,j,0,0,2);
                    mp[i][j] = 0;
                }
            }
        }
        while(true){
            Fish findFish = findF(babyShark,N);
            babyShark.y = findFish.y;
            babyShark.x = findFish.x;
            if(babyShark.y == -1) break;
            babyShark.exp ++;
            if(babyShark.exp == babyShark.size){
                babyShark.exp = 0;
                babyShark.size++;
            }
        }
        System.out.println(answer);
    }
    // 거리가 가까운 물고기 찾기
    // return 좌표값(y,x) , 이동거리 , input 물고기 size,시작 좌표
    public static Fish findF(Shark start,int N) {
        boolean[][] vst = new boolean[MAX][MAX];
        boolean stop = false;
        Queue<Fish> q = new LinkedList<>();
        q.add(start);
        vst[start.y][start.x] = true;
        Fish retFish = new Fish(INF,INF,INF);
        LinkedList<Fish> cd = new LinkedList<Fish>();
        int stopD = INF;
        while(!q.isEmpty()) {
            Fish cur = q.poll();
            if (cur.dis > stopD) continue;
            for (int i = 0; i < 4; i++) {
                int tx = cur.x + dx[i];
                int ty = cur.y + dy[i];
                if (ty < 0 || ty >= N || tx < 0 || tx >= N) continue;
                if (vst[ty][tx]) continue;
                if (mp[ty][tx] > start.size) continue;
                if (mp[ty][tx] < start.size && mp[ty][tx] != 0) {
                    vst[ty][tx] = true;
                    stopD = cur.dis;
                    cd.add(new Fish(ty, tx, cur.dis + 1));
                    continue;
                }
                vst[ty][tx] = true;
                Fish movedFish = new Fish(ty, tx, cur.dis + 1);
                q.add(movedFish);
                continue;
            }
        }
        cd.sort(Comparator.comparing(Fish::getY).thenComparing(Fish::getX));
        if(cd.isEmpty()) return new Fish(-1,-1,0);
        mp[cd.element().y][cd.element().x] = 0;
        answer+=stopD+1;
        return cd.element();
    }
}

class Fish{
    int y;
    int x;
    int dis;
    public Fish(){}
    public Fish(int y, int x, int dis) {
        this.y = y;
        this.x = x;
        this.dis = dis;
    }

    public int getY() {
        return y;
    }

    public int getX() {
        return x;
    }

    public int getDis() {
        return dis;
    }
}
class Shark extends Fish{
    int exp;
    int size;

    public Shark(int exp, int size) {
        this.exp = exp;
        this.size = size;
    }

    public Shark(int y, int x, int dis, int exp, int size) {
        super(y, x, dis);
        this.exp = exp;
        this.size = size;
    }
}