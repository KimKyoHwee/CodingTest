import java.io.*;
import java.util.*;

class Solution {
    public long solution(int cap, int n, int[] deliveries, int[] pickups) {
        long answer = 0;
        int d=0, p=0;
        for(int i=n-1;i>=0;i--){
            d-=deliveries[i];
            p-=pickups[i];
            if(d<0||p<0){
                while(true){
                    if(d>=0&&p>=0) break;
                    answer+=(2*(i+1));
                    //System.out.println((i+1)+"만큼추가");
                    d+=cap;
                    p+=cap;
                }
            }
        }
        return answer;
    }
}