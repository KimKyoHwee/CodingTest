import java.lang.*;
import java.io.*;
import java.util.*;

class Solution {
    static int[] head;
    static class Edge implements Comparable<Edge>{
        int start;
        int end;
        int dist;
        Edge(int start, int end, int dist){
            this.start=start;
            this.end=end;
            this.dist=dist;
        }
        @Override
        public int compareTo(Edge e){
            return this.dist-e.dist;
        }
    }
    public static int getHead(int node){
        if(head[node]==node) return node;
        else return getHead(head[node]);
    }
    public static void union(int node1, int node2){
        if(getHead(node1)<=getHead(node2)) head[getHead(node1)]=getHead(node2);
        else head[getHead(node1)]=getHead(node2);
    }
    public int solution(int n, int[][] costs) {
        head=new int[n];
        for(int i=0;i<n;i++) head[i]=i;//초기화
        PriorityQueue<Edge> pq=new PriorityQueue<>();
        List<Edge> finalEdges=new ArrayList<>();
        for(int i=0;i<costs.length;i++){
            int[] cost=costs[i];
            pq.add(new Edge(cost[0],cost[1],cost[2]));
            pq.add(new Edge(cost[1],cost[0],cost[2]));
        }
        int nodeNum=1;
        while(true){
            if(nodeNum==n) break;
            Edge edge=pq.peek();
            pq.poll();
            if(getHead(edge.start)==getHead(edge.end)) continue;
            union(edge.start, edge.end);
            nodeNum++;
            finalEdges.add(edge);
        }
        int answer = 0;
        for(int i=0;i<(n-1);i++){
            answer+=(finalEdges.get(i).dist);
        }
        return answer;
    }
}