import java.lang.*;
import java.io.*;
import java.util.*;
class Solution {
    int answer=0, N;
    public void dfs(int k, int nowAnswer, boolean[] visited, int[][] dungeons, int depth){
        if(depth==N){
            answer=Math.max(nowAnswer, answer);
            return;
        }
        for(int i=0;i<N;i++){ //다음에 방문할곳
            if(visited[i]) continue;
            if(k<dungeons[i][0]) {
                answer=Math.max(nowAnswer, answer);
                continue;
            }
            //System.out.println(i+"방문, ");
            visited[i]=true;
            dfs(k-dungeons[i][1], nowAnswer+1, visited, dungeons, depth+1);
            visited[i]=false;
        }
    }
    
    public int solution(int k, int[][] dungeons) {
        N=dungeons.length;
        boolean[] visited=new boolean[N];
        for(int i=0;i<N;i++) visited[i]=false;
        for(int i=0;i<N;i++){
            if(k<dungeons[i][0]) continue;
            //System.out.print(i+"번째\n");
            visited[i]=true;
            dfs(k-dungeons[i][1],1,visited, dungeons, 1);
            visited[i]=false;
        }
        return answer;
    }
}