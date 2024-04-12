import java.lang.*;
import java.util.*;
import java.io.*;
class Solution {
    public static boolean[] visited;
    
    public static void dfs(int node, int[][] computers){
        visited[node]=true;
        for(int i=0;i<computers[node].length;i++){
            if(computers[node][i]==0||visited[i]) continue;
            dfs(i, computers);
        }
    }
    public int solution(int n, int[][] computers) {
        int answer = 0;
        visited=new boolean[n];
        Arrays.fill(visited, false);
        for(int i=0;i<n;i++){
            if(visited[i]) continue;
            dfs(i, computers);
            answer++;
        }    
        return answer;
    }
}