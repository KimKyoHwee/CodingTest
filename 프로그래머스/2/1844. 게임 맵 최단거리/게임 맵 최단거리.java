import java.lang.*;
import java.io.*;
import java.util.*;
class Solution {
    public static int[][] lastY;
    public static int[][] lastX;
    public static int[] moveY={-1,1,0,0}; //상하좌우
    public static int[] moveX={0,0,-1,1};
    public static void bfs(int[][] maps, boolean[][] visited, int n, int m){
        visited[0][0]=true;
        Queue<int[]> q=new LinkedList<>();
        q.add(new int[]{0,0});
        lastY[0][0]=0;
        lastX[0][0]=0;
        while(!q.isEmpty()){
            int[] node=q.peek();
            q.poll();
            int nowY=node[0];
            int nowX=node[1];
            for(int i=0;i<4;i++){
                int nextY=nowY+moveY[i];
                int nextX=nowX+moveX[i];
                if(nextY<0||nextY>=n||nextX<0||nextX>=m||maps[nextY][nextX]==0||visited[nextY][nextX]) continue;
                q.add(new int[]{nextY, nextX});
                visited[nextY][nextX]=true;
                lastY[nextY][nextX]=nowY;
                lastX[nextY][nextX]=nowX;
                if(nextY==(n-1)&&nextX==(m-1)) break;
            }
        }
    }
    public int solution(int[][] maps) {
        int answer = 1;
        int n=maps.length;
        int m=maps[0].length;
        boolean[][] visited=new boolean[n][m];
        lastY=new int[n][m];
        lastX=new int[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) {
                visited[i][j]=false;
                lastY[i][j]=-1;
                lastX[i][j]=-1;
            }
        }
        bfs(maps, visited, n, m);
        if(lastY[n-1][m-1]==-1&&lastX[n-1][m-1]==-1) return -1;
        int nowY=n-1;
        int nowX=m-1;
        while(true){
            answer++;
            int nextY=lastY[nowY][nowX];
            int nextX=lastX[nowY][nowX];
            if(nextY==0&&nextX==0) break;
            nowY=nextY;
            nowX=nextX;
        }
        return answer;
    }
}