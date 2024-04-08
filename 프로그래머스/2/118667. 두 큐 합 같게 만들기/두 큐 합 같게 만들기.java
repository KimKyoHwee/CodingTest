import java.io.*;
import java.lang.*;
import java.util.*;
class Solution {
    public static long sum=0;
    public static Queue<Integer> q1;
    public static Queue<Integer> q2;
    public static long sum1=0;
    public static long sum2=0;
    public static int turn=0;
    public int solution(int[] queue1, int[] queue2) {
        q1=new LinkedList<>();
        q2=new LinkedList<>();
        for(int i=0;i<queue1.length;i++){
            int a=queue1[i];
            int b=queue2[i];
            q1.add(a);
            q2.add(b);
            sum+=a;
            sum+=b;
            sum1+=a;
            sum2+=b;
        }
        sum/=2; //각 큐의 목표합, 큐에 값 다 옮기기 완료
        int maxTurn=queue1.length*3; //양쪽 큐의 모든값들이 빠져나갔다 들어가는게 최대치
        boolean flag=false; //성공여부
        while(maxTurn>0){
            if(sum1==sum&&sum2==sum) {
                flag=true;
                break;
            }
            turn++;
            maxTurn--;
            if(sum1>=sum2){
                int peek=q1.peek();
                q1.poll();
                q2.add(peek);
                sum1-=peek;
                sum2+=peek;
            }
            else{
                int peek=q2.peek();
                q2.poll();
                q1.add(peek);
                sum1+=peek;
                sum2-=peek;
            }
        }
        if(!flag) turn=-1;
        System.out.println(turn);
        return turn;
    }
}