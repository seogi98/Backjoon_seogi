import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int W = sc.nextInt();
        int L = sc.nextInt();
        Queue<Integer> truck = new LinkedList<>();
        Queue<Integer> bridge = new LinkedList<>();
        for(int i=0;i<N;i++){
            truck.add(sc.nextInt());
        }
        for(int i=0;i<W;i++){
            bridge.add(0);
        }
        int answer=0;
        // 현재 다리 무게
        int sum = 0;
        while (!bridge.isEmpty()){
            sum -= bridge.poll();
            answer++;
            if(truck.isEmpty()) continue;
            if(sum + truck.element() <= L){
                sum += truck.element();
                bridge.add(truck.poll());
            }
            else{
                bridge.add(0);
            }
        }
        System.out.println(answer);
    }
}


