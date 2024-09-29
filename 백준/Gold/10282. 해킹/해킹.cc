#include <iostream>
#include <map>
#include <unordered_map>
#include <utility>
#include <queue>
using namespace std;
int N;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<pair<int, int>> answer;
    cin>>N;
    while(N--){
        int n,d,c;
        cin>>n>>d>>c;
        map<int, vector<pair<int,int>>> edge;
        for(int i=0;i<d;i++){
            int a,b,s;
            cin>>a>>b>>s;
            edge[b].push_back({a,s});
        }
        //엣지 입력완료
        vector<int> dijk(n+1, 987654321);
        //vector<bool> visited(n+1, false);
        dijk[c]=0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        pq.push({0,c});
        while(!pq.empty()){
            pair<int, int> nowP=pq.top();
            pq.pop();
            int nowIndex=nowP.second;
            int nowWeight=nowP.first;
            //visited[nowIndex]=true;
            for(int i=0;i<edge[nowIndex].size();i++){
                int nextIndex=edge[nowIndex][i].first;
                int nextWeight=nowWeight+edge[nowIndex][i].second;
                //if(visited[nextIndex]) continue;
                if(dijk[nextIndex]>nextWeight){
                    dijk[nextIndex]=nextWeight;
                    pq.push({nextWeight, nextIndex});
                }
            }
        }
        int resultA=1;
        int resultB=0;
        for(int i=1;i<=n;i++){
            if(dijk[i]!=987654321){
                if(i==c) continue;
                resultA++;
                resultB=max(resultB, dijk[i]);
            }
        }
        answer.push_back({resultA, resultB});
    }
    for(int i=0;i<answer.size();i++) cout<<answer[i].first<<" "<<answer[i].second<<"\n";
    return 0;
}