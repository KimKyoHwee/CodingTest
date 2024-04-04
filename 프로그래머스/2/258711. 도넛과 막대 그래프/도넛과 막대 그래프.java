import java.io.*;
import java.util.*;
//import java.lang.*;


class Solution {
    public int[] solution(int[][] edges) {
        int[] answer = {0,0,0,0};
        //List<Integer> out=new ArrayList<>(edges.length+1);
        //List<Integer> in=new ArrayList<>(edges.length+1);
        int[] out= new int[1000001];
        int[] in= new int[1000001];
        Arrays.fill(out, 0);  //이건 배열
        Arrays.fill(in, 0);
        //Collections.fill(out,0);  //이건 Array List
        //Collections.fill(in, 0);
        int maxNode=0; //제일 마지막 노드 번호
        for(int i=0;i<edges.length;i++){
            int a = edges[i][0];
            int b = edges[i][1];
            if(maxNode<a) maxNode=a;
            if(maxNode<b) maxNode=b;
            out[a]++; 
            in[b]++;  //ArrayList에서 사용 불가
        }
        for(int i=1;i<=maxNode;i++){
            if(in[i]==0&&out[i]==0) continue;
            if(in[i]==0&&out[i]>=2){
                answer[0]=i;
            }
            else if(out[i]==0&&in[i]>=1) answer[2]++;
            else if(in[i]>=2&&out[i]>=2) answer[3]++;
        }
        answer[1]=out[answer[0]]-(answer[2]+answer[3]);
        return answer;
    }
}