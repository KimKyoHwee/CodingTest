import java.lang.*;
import java.util.*;
import java.io.*;
class Solution {
    static class Node implements Comparable<Node>{
        int index;
        int dist;
        Node(int index, int dist){
            this.index=index;
            this.dist=dist;
        }
        @Override
        public int compareTo(Node b){
            return this.dist-b.dist;
        }
    }

    public int solution(int n, int[][] edge) {
        List<List<int[]>> board=new ArrayList<List<int[]>>(); 
        //board[i]={{a,b}, {c,d}};
        //i에서 a까지 b의거리, c까지 d의거리인데, 여기선 거리 다 1임
        int[] dist=new int[n+1]; //1번노드로부터의 거리
        int[] nearest=new int[n+1]; //자기가 연결된 노드
        for(int i=1;i<=n;i++) {
            dist[i]=2100000000;
            nearest[i]=1;
        } //초기화 : 현재 거리 다 MAX, 가장 가까운건 시작노드
        for(int i=0;i<=n;i++) board.add(new ArrayList<>()); //보드 틀만들기
        for(int[] e:edge){ //edge 추가해주기
            board.get(e[0]).add(new int[]{e[1],1}); 
            board.get(e[1]).add(new int[]{e[0], 1}); 
        }
        //초기화끝
        for(int i=2;i<=n;i++) dist[i]=2100000000;
        //다익스트라 시작
        dist[1]=0;
        PriorityQueue<Node> pq=new PriorityQueue<>();
        pq.add(new Node(1,0));
        while(!pq.isEmpty()){
            Node node=pq.peek();
            pq.poll();
            for(int i=0;i<board.get(node.index).size();i++){
                int[] next=board.get(node.index).get(i);
                int nextIndex=next[0];
                int nextDist=next[1];
                if(dist[nextIndex]>(dist[node.index]+nextDist)){
                    dist[nextIndex]=(dist[node.index]+nextDist);
                    nearest[nextIndex]=node.index;
                    pq.add(new Node(nextIndex, dist[nextIndex]));
                }
            }
        }
        int maxDist=0;
        for(int i=2;i<=n;i++) {
            if(maxDist<dist[i]) maxDist=dist[i];
        }
        int answer=0;
        for(int i=2;i<=n;i++){
            if(maxDist==dist[i]) answer++;
        }
        return answer;
    }
}