import java.io.*;
import java.util.*;


public class Main {
    public static void main(String[] args) throws IOException {
//        final int MAX = 600000;
        Cal c = new Cal();
        HashMap<String, Integer> hm = new HashMap<String, Integer>() {{
            put("*", 2);
            put("/", 2);
            put("+", 1);
            put("-", 1);
        }};
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String str = bf.readLine();
        ArrayList<String> opS = new ArrayList<>();
        ArrayList<String> numS = new ArrayList<>();
        String curS = new String();
        for(int i=0;i<str.length();i++){
            if(" /+-*".indexOf(str.charAt(i))>0){
                opS.add(str.charAt(i)+"");
                numS.add(curS);
                curS = "";
                continue;
            }
            curS += str.charAt(i);
        }
        numS.add(curS);

        // 만약에 가장 앞에 - 가 붙어있을 경우 예외처리
        if (str.charAt(0) == '-') {
            numS.set(1,"-"+numS.get(1));
            opS.set(0,"");
        }
        ArrayDeque<Long> num = new ArrayDeque<>();
        ArrayDeque<String> op = new ArrayDeque<>();
        for (String cur : numS) {
            if(cur.equals("")) continue;
            num.add(Long.parseLong(cur));
        }
        for (String cur : opS) {
            if(cur.equals("")) continue;
            op.add(cur);
        }
        long []fn = new long [2];
        long []bn = new long [2];
        long []result = new long[2];
        // 만약에 연산이 3개 이상일 경우
        while(op.size() >= 2 && num.size() >= 3){
            String fo = op.pollFirst();
            String lo = op.pollLast();
            fn[0] = num.pollFirst();
            fn[1] = num.pollFirst();
            bn[0] = num.pollLast();
            if(num.size() == 0){
                bn[1] = fn[1];
            }
            else{
                bn[1] = num.pollLast();
            }
            result[0] = c.cal(fo,fn[0],fn[1]);
            result[1] = c.cal(lo,bn[1],bn[0]);
            int switchNum = 0;
            if(hm.get(fo) == hm.get(lo)){
                if(result[0] < result[1]){
                    switchNum = 1;
                }
            }
            else if(hm.get(fo) < hm.get(lo)){
                switchNum = 1;
            }
            // 먼저 뺀 것 부터 넣어야한다.
            if(switchNum == 0){
                num.addFirst(result[0]);
                if(!op.isEmpty())
                    num.addLast(bn[1]);
                num.addLast(bn[0]);
                op.addLast(lo);
                continue;
            }
            num.addLast(result[1]);
            if(!op.isEmpty())
                num.addFirst(fn[1]);
            num.addFirst(fn[0]);
            op.addFirst(fo);
        }
        long answer = 0;
        if(num.size() == 1){
            answer = num.poll();
        }
        else{
            // 마지막 남은 연산 하나 계산하자
            answer = c.cal(op.poll(),num.poll(),num.poll());
        }
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(answer+"");
        bw.flush();
        bw.close();
    }
}
class Cal{
    long cal(String op, long n1,long n2){
        if(op.equals("*"))
            return n1*n2;
        if(op.equals("/"))
            return n1/n2;
        if(op.equals("+"))
            return n1+n2;
        if(op.equals("-"))
            return n1-n2;
        return -1;
    }
}
