#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N,M,R,result=0; //지역 개수, 수색범위, 길의 개수
vector<int> items, dist;
vector<vector<pair<int, int>>> edges;
void dijkstra(int start){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    pq.push({0,start});
    vector<bool> visited(N+1, false);
    for(int i=1;i<=N;i++) dist[i]=987654321;
    dist[start]=0;
    for(int i=0;i<edges[start].size();i++){
        int next=edges[start][i].first;
        int weight=edges[start][i].second;
        dist[next]=weight;
    }
    while(!pq.empty()){
        int now=pq.top().second;
        int nowDist=pq.top().first;
        pq.pop();
        visited[now]=true;
        for(int i=0;i<edges[now].size();i++){
            int next=edges[now][i].first;
            if(visited[next])continue;
            int nextDist=nowDist+edges[now][i].second;
            dist[next]=min(dist[next], nextDist);
            pq.push({dist[next], next});
        }
    }
}
int main(){
    cin>>N>>M>>R;
    items.resize(N+1);
    dist.resize(N+1);
    edges.resize(N+1);
    for(int i=1;i<=N;i++) cin>>items[i];
    for(int i=0;i<R;i++){
        int a,b,c; cin>>a>>b>>c;
        edges[a].push_back({b,c});
        edges[b].push_back({a,c});
    }
    for(int i=1;i<=N;i++){
        int nowResult=0;
        dijkstra(i);
        for(int j=1;j<=N;j++){
            if(dist[j]<=M) nowResult+=items[j];
        }
        result=max(result, nowResult);
    }
    cout<<result;

    return 0;
}