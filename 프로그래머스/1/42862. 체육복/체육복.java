import java.lang.*;
import java.io.*;
import java.util.*;
class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = 0;
        int[] inputs=new int[n+1];
        for(int i=0;i<=n;i++) inputs[i]=1;
        for(int i=0;i<lost.length;i++) inputs[lost[i]]--;
        for(int i=0;i<reserve.length;i++) inputs[reserve[i]]++;
        for(int i=1;i<=n;i++){
            if(inputs[i]<=1) continue;
            if((i-1)>=1&&inputs[i-1]==0){
                inputs[i-1]++;
                inputs[i]--;
            }
            else if((i+1)<=n&&inputs[i+1]==0){
                inputs[i+1]++;
                inputs[i]--;
            }
        }
        for(int i=1;i<=n;i++){
            if(inputs[i]>=1) answer++;
        }
        return answer;
    }
}