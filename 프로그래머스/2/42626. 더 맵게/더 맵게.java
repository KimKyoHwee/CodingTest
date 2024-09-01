import java.lang.*;
import java.io.*;
import java.util.*;
class Solution {
    public int mix(int first, int second){
        return first+(second*2);
    }
    public int solution(int[] scoville, int K) {
        int answer = 0;
        boolean done=false;
        PriorityQueue<Integer> pq=new PriorityQueue<>();
        for(int i=0;i<scoville.length;i++) pq.offer(scoville[i]);
        while(pq.size()>=2){
            int first=pq.poll();
            int second=pq.poll();
            if(first>=K) {
                done=true;
                break;
            }
            int next=mix(first, second);
            pq.offer(next);
            answer++;
        }
        if(!done){
            int first=pq.poll();
            if(first<K) answer=-1; 
        }
        return answer;
    }
}