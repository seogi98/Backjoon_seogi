import java.util.*;

class Main{
    static final int MAX = 51;
    static int []dy = {0,1,0,-1};
    static int []dx = {1,0,-1,0};
    static int[][] spread(int [][] mp,int R,int C){
        int [][] ans = new int[MAX][MAX];
        Queue<Dirty> q = new LinkedList<>();
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(mp[i][j] != 0){
                    q.add(new Dirty(i,j,mp[i][j]));
                }
            }
        }
        Queue<Dirty> sumQ = new LinkedList<>();
        while(!q.isEmpty()){
            Dirty cur = q.poll();
            int dirSize = 0;
            for(int i=0;i<4;i++){
                Dirty nextD = new Dirty(cur.y+dy[i],cur.x+dx[i],cur.size);
                if(nextD.x < 0 || nextD.x >= C || nextD.y < 0 || nextD.y >= R) continue;
                if(mp[nextD.y][nextD.x] == -1) continue;
                dirSize++;
                nextD.size /= 5;
                sumQ.add(nextD);
            }
            cur.size = cur.size-((cur.size/5)*dirSize);
            sumQ.add(cur);
        }
        while(!sumQ.isEmpty()){
            Dirty front = sumQ.poll();
            ans[front.y][front.x] += front.size;
        }
        return ans;
    }
    static int[][] refresh(int [][] mp,Dirty upAirFresh, Dirty downAirFresh,int R,int C){
        int [][] ans = mp;
        Queue<Dirty> q = new LinkedList<>();
        // up
        // 오른쪽 방향
        for(int i=1;i<C-1;i++){
            int y1 = upAirFresh.y;
            q.add(new Dirty(y1,i+1,mp[y1][i]));
            ans[y1][i] = 0;
        }
        // 위쪽 방향
        for(int i=upAirFresh.y;i>=1;i--){
            int x1 = C-1;
            q.add(new Dirty(i-1,x1,mp[i][x1]));
            ans[i][x1] = 0;
        }
        // 왼쪽
        for(int i=C-1;i>0;i--){
            int y1 = 0;
            q.add(new Dirty(y1,i-1,mp[y1][i]));
            ans[y1][i] = 0;
        }
        // 아래쪽 방향
        for(int i=0;i< upAirFresh.y;i++){
            int x1 = 0;
            q.add(new Dirty(i+1,x1,mp[i][x1]));
            ans[i][x1] = 0;
        }
        // down
        // 오른쪽
        for(int i=1;i<C-1;i++)
        {
            int Y1 = downAirFresh.y;
            q.add(new Dirty(Y1,i+1,mp[Y1][i]));
            ans[Y1][i] =0;
        }
        // 아래쪽 방향
        for(int i=downAirFresh.y;i<R-1;i++){
            int x1 = C-1;
            q.add(new Dirty(i+1,x1,mp[i][x1]));
            ans[i][x1] = 0;
        }
        // 왼쪽 방향
        for(int i=C-1;i>0;i--)
        {
            int Y1 = R-1;
            q.add(new Dirty(Y1,i-1,mp[Y1][i]));
            ans[Y1][i]=0;
        }
        // 위쪽 방향
        for(int i=R-1;i>downAirFresh.y;i--)
        {
            int X1 = 0;
            q.add(new Dirty(i-1,X1,mp[i][X1]));
            ans[i][X1]=0;
        }
        while(!q.isEmpty()){
            Dirty cur = q.poll();
            if(cur.y == upAirFresh.y && cur.x == upAirFresh.x) continue;
            if(cur.y == downAirFresh.y && cur.x == downAirFresh.x) continue;
            ans[cur.y][cur.x] = cur.size;
        }
        return ans;
    }
    static int countDirty(int[][] mp,int R,int C){
        int sum =0;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(mp[i][j] == -1) continue;
                sum+=mp[i][j];
            }
        }
        return sum;
    }
    static void seeM(int [][] mp,int R,int C){
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                System.out.print(mp[i][j]+" ");
            }
            System.out.println();
        }
        System.out.println();
    }
public static void main(String[] args) {
    int R,C,T;
    Scanner sc = new Scanner(System.in);
    R = sc.nextInt();
    C = sc.nextInt();
    T = sc.nextInt();
    Dirty upAirFresh = new Dirty(-1,-1,-1);
    Dirty downAirFresh = new Dirty(-1,-1,-1);
    int [][] mp =new int[MAX][MAX];
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            mp[i][j] = sc.nextInt();
            if(mp[i][j] == -1){
                // 처음 나온거면 upfresh
                if(upAirFresh.x == -1) upAirFresh = new Dirty(i,j,0);
                else downAirFresh = new Dirty(i,j,0);
//                mp[i][j] = 0;
            }
        }
    }
    for(int i=0;i<T;i++){
        mp = spread(mp,R,C);
//            seeM(mp,R,C);
        mp = refresh(mp,upAirFresh,downAirFresh,R,C);
//            seeM(mp,R,C);
    }
    System.out.println(countDirty(mp,R,C));
}
}
class Dirty{
    int y;
    int x;
    int size;

    public Dirty(int y, int x, int size) {
        this.y = y;
        this.x = x;
        this.size = size;
    }
}