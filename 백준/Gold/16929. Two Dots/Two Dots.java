import java.util.*;
import java.io.*;
import java.lang.*;;
class Main{
    public static char[][] board;
    public static boolean[][] visited;
    public static int N,M;
    public static int[] moveY={-1,0,1,0};
    public static int[] moveX={0,1,0,-1}; //상우하좌
    public static int startY, startX;
    public static char color;
    public static void getInput(Scanner sc){
        N=sc.nextInt();
        M=sc.nextInt();
        board=new char[N][M];
        visited=new boolean[N][M];
        sc.nextLine();
        for(int i=0;i<N;i++){
            String str=sc.nextLine();
            for(int j=0;j<M;j++) {
                board[i][j] = str.charAt(j);
            }
        }
    }
    public static void printBoard(){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++) System.out.print(board[i][j]+" ");
            System.out.println();
        }
    }
    public static boolean dfs(int nowY, int nowX, int cnt){
        visited[nowY][nowX]=true;
        for(int i=0;i<4;i++){
            int nextY=nowY+moveY[i];
            int nextX=nowX+moveX[i];
            if(nextY==startY&&nextX==startX&&cnt+1>=4) return true;
            if(nextY<0||nextY>=N||nextX<0||nextX>=M||visited[nextY][nextX]) continue;
            if(color!=board[nextY][nextX]) continue;
            if(dfs(nextY,nextX,cnt+1)) return true;
        }
        return false;
    }
    public static void fillVisitedFalse(){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                visited[i][j]=false;
            }
        }
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        getInput(sc);
        //printBoard();
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                color=board[i][j];
                startY=i;
                startX=j;
                fillVisitedFalse();
                if(dfs(i,j,1)){
                    System.out.println("Yes");
                    return;
                }
            }
        }
        System.out.println("No");
        return;
    }
}