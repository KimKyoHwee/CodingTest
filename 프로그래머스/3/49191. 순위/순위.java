import java.lang.*;
import java.io.*;
import java.util.*;
class Solution {
    public int solution(int n, int[][] results) {
        int[][] graph=new int[n+1][n+1];
        for(int i=0;i<results.length;i++){
            int win=results[i][0];
            int lose=results[i][1];
            graph[win][lose]=1;
            graph[lose][win]=-1;
        }
        for(int i=1;i<=n;i++){  //i번 인덱스 걸쳐가는거
            for(int j=1;j<=n;j++){ //j번 인덱스 시작
                for(int k=1;k<=n;k++){ //j->k로 가는법
                    if(graph[j][i]==1&&graph[i][k]==1){
                        graph[j][k]=1;
                        graph[k][j]=-1;
                    }
                }
            }
        }
        int answer = 0;
        for(int i=1;i<=n;i++){
            boolean flag=true;
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                if(graph[i][j]==0) flag=false;
            }
            if(flag) answer++;
        }
        return answer;
    }
}