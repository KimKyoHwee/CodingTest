import java.lang.*;
import java.io.*;
import java.util.*;

class Solution {
    int[][] maxDp;
    int[][] minDp;
    int[] inputs;
    char[] oper;
    int N;
    public int solution(String arr[]) {
        N=(arr.length+1)/2;
        maxDp=new int[N+1][N+1];
        minDp=new int[N+1][N+1];
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                maxDp[i][j]=-987654321;
                minDp[i][j]=987654321;
            }
        }
        inputs=new int[N+1];
        oper=new char[N];
        int index=1;
        for(int i=0;i<arr.length;i+=2){
            inputs[index]=Integer.parseInt(arr[i]);
            index++;
        }
        index=1;
        for(int i=1;i<arr.length;i+=2){
            oper[index]=arr[i].charAt(0);
            index++;
        }
        for(int i=1;i<=N;i++){
            maxDp[i][i]=inputs[i];
            minDp[i][i]=inputs[i];
        }
        for(int k=1;k<N;k++){  //diagonal
            for(int i=1;i<=N-k;i++){ //start index
                int next=i+k;  //end index
                for(int j=i;j<next;j++){ //opertator index
                    char nowOper=oper[j];
                    if(nowOper=='-'){
                        maxDp[i][next]=Math.max(maxDp[i][next],maxDp[i][j]-minDp[j+1][next]);
                        minDp[i][next]=Math.min(minDp[i][next],minDp[i][j]-maxDp[j+1][next]);
                    }
                    else{
                        maxDp[i][next]=Math.max(maxDp[i][next], maxDp[i][j]+maxDp[j+1][next]);
                        minDp[i][next]=Math.min(minDp[i][next], minDp[i][j]+minDp[j+1][next]);
                    }
                }
            }
        }
        /*
        for(int i=1;i<=N;i++){
            for(int j=i;j<=N;j++){
                if(i==j) continue;
                for(int k=i;k<j;k++){
                    char nowOper=oper[k];
                    if(nowOper=='-'){
                        maxDp[i][j]=Math.max(maxDp[i][j],maxDp[i][k]-minDp[k+1][j]);
                        minDp[i][j]=Math.min(minDp[i][j],minDp[i][k]-maxDp[k+1][j]);
                    }
                    else{
                        maxDp[i][j]=Math.max(maxDp[i][j], maxDp[i][k]+maxDp[k+1][j]);
                        minDp[i][j]=Math.min(minDp[i][j], minDp[i][k]+minDp[k+1][j]);
                    }
                }
            }
        }
        */
        int answer = maxDp[1][N];
        return answer;
    }
}