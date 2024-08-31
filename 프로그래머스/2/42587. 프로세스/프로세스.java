import java.lang.*;
import java.io.*;
import java.util.*;
class Solution {
    public static Queue<Integer> q=new LinkedList<>();
    public static Queue<Integer> q2=new LinkedList<>();
    
    public int solution(int[] priorities, int location) {
        int answer = 0;
        for(int i=0;i<priorities.length;i++) {
            q.offer(priorities[i]); //큐에 대입
            q2.offer(i);
        }
        
        Integer[] inputs=new Integer[priorities.length];
        for(int i=0;i<priorities.length;i++) inputs[i]=priorities[i];
        Arrays.sort(inputs, new Comparator<Integer>(){
            @Override
            public int compare(Integer first, Integer second){
                return Integer.compare(second, first);
            }
        });
        
        int index=0;
        while(!q.isEmpty()){
            int now=q.poll();
            int nowIndex=q2.poll();
            if(now<inputs[index]) {
                q.offer(now);
                q2.offer(nowIndex);
            }
            else{
                index++;
                if(nowIndex==location){
                    answer=index;
                    break;
                }
            }
        }
        return answer;
    }
}