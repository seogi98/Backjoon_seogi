import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        ArrayList J = new ArrayList<Pair>();
        ArrayList B = new ArrayList<Integer>();
        PriorityQueue pq = new PriorityQueue<Pair>();
        for(int i=0;i<N;i++){
            StringTokenizer st2 = new StringTokenizer(bf.readLine());
            Pair p = new Pair(Integer.parseInt(st2.nextToken()),Integer.parseInt(st2.nextToken()));
            J.add(p);
        }
        for(int i=0;i<K;i++){
            B.add(Integer.parseInt(bf.readLine()));
        }
        Collections.sort(J);
        Collections.sort(B);
        int jp = 0;
        long ans = 0;
        for(int i=0;i<B.size();i++){
           int bw = (int) B.get(i);
           while(jp < J.size() && ((Pair)J.get(jp)).first <= bw){
               pq.add(new Pair(-((Pair) J.get(jp)).second,((Pair) J.get(jp)).first));
               jp++;
           }
           if(!pq.isEmpty()){
               ans -= ((Pair)pq.poll()).first;
           }
        }
        System.out.println(ans);
    }
}
class Pair implements Comparable<Pair>{
    int first,second;

    Pair(int f,int s){
        this.first = f;
        this.second = s;
    }
    public int compareTo(Pair p){
        if(this.first == p.first)
            return Integer.compare(this.second,p.second);
        return Integer.compare(this.first,p.first);
    }
}
