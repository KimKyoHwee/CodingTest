import java.lang.*;
import java.io.*;
import java.util.*;
import java.util.Map.*;
import java.util.AbstractMap.*;
class Solution {
    ArrayList<Entry<Integer, Integer>>[] edges;
    public int[] dijkstra(int start, int n){
        int[] dist=new int[n+1];
        Arrays.fill(dist, 987654321);
        PriorityQueue<Entry<Integer, Integer>> pq=new PriorityQueue<>(new Comparator<>(){
            @Override
            public int compare(Entry<Integer, Integer> a, Entry<Integer,Integer> b){
                return Integer.compare(a.getKey(), b.getKey());
            }
        });
        pq.offer(new SimpleEntry<>(0, start));
        while(!pq.isEmpty()){
            Entry<Integer, Integer> nowEntry=pq.poll();
            int nowWeight=nowEntry.getKey();
            int nowIndex=nowEntry.getValue();
            for(int i=0;i<edges[nowIndex].size();i++){
                int nextIndex=edges[nowIndex].get(i).getKey();
                int nextWeight=edges[nowIndex].get(i).getValue();
                if(dist[nextIndex]>nowWeight+nextWeight){
                    dist[nextIndex]=nowWeight+nextWeight;
                    pq.offer(new SimpleEntry<>(dist[nextIndex], nextIndex));
                }
            }
        }
        return dist;
    }
    
    public int solution(int n, int s, int a, int b, int[][] fares) {
        edges=new ArrayList[n+1];
        int[][] allEdges=new int[n+1][n+1];
        for(int i=1;i<=n;i++) {
            Arrays.fill(allEdges[i], 987654321);
            allEdges[i][i]=0;
        }
        for(int i=0;i<=n;i++) edges[i]=new ArrayList<>();
        int answer = 987654321;
        for(int i=0;i<fares.length;i++){
            int now=fares[i][0];
            int next=fares[i][1];
            int weight=fares[i][2];
            edges[now].add(new SimpleEntry<>(next, weight));
            edges[next].add(new SimpleEntry<>(now, weight));
            allEdges[now][next]=Math.min(allEdges[now][next], weight);
            allEdges[next][now]=Math.min(allEdges[next][now], weight);
        }
        int[] sWeight=dijkstra(s, n);
        int[] aWeight=dijkstra(a, n);
        int[] bWeight=dijkstra(b, n);
        for(int i=1;i<=n;i++){
            if(sWeight[i]>=987654321||aWeight[i]>=987654321||
              bWeight[i]>=987654321) continue;
            answer=Math.min(answer, sWeight[i]+aWeight[i]+bWeight[i]);
        }
        
        answer=Math.min(sWeight[b]+bWeight[a], answer);
        answer=Math.min(sWeight[a]+aWeight[b], answer);
        answer=Math.min(sWeight[a]+sWeight[b], answer);
        
        
        //s-> i + (i->a)+(i->b)
        return answer;
    }
}