#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
int N,M;
vector<pair<int, int>> input[50001];
vector<int> map;

void dijkstra(){
    map[1]=0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0,1});
    while(!pq.empty()){
        int nowNode=pq.top().second;
        int nowLen=pq.top().first;
        pq.pop();
        for(int i=0;i<input[nowNode].size();i++){
            int nextNode=input[nowNode][i].first;
            int nextLen=nowLen+input[nowNode][i].second;
            if(map[nextNode]>nextLen){
                map[nextNode]=nextLen;
                pq.push({nextLen, nextNode});
            }
        }
    }
}
int main(){
    cin>>N>>M;
    map.resize(N+1,2100000000);
    while(M--){
        int a,b,c;
        cin>>a>>b>>c;
        input[a].push_back({b,c});
        input[b].push_back({a,c});
    }
    dijkstra();
    cout<<map[N];
    return 0;
}