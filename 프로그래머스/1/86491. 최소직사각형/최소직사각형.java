import java.lang.*;
import java.io.*;
import java.util.*;
class Solution {
    public int solution(int[][] sizes) {
        PriorityQueue <Integer> minQ=new PriorityQueue<>(new Comparator<Integer>(){
           @Override
            public int compare(Integer first, Integer second){
                return Integer.compare(second, first);
            }
        });
        PriorityQueue <Integer> maxQ=new PriorityQueue<>(new Comparator<Integer>(){
           @Override
            public int compare(Integer first, Integer second){
                return Integer.compare(second, first);
            }
        });
        for(int i=0;i<sizes.length;i++){
            int first=sizes[i][0];
            int second=sizes[i][1];
            if(first<second){
                minQ.offer(first);
                maxQ.offer(second);
            }
            else{
                minQ.offer(second);
                maxQ.offer(first);
            }
        }
        int answer = minQ.poll()*maxQ.poll();
        return answer;
    }
}