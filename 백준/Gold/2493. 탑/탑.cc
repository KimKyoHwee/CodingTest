#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<pair<int, int>> input;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  //자기 레이저를 받아줄 탑을 찾는 대기 큐
int N;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first!=b.first) return a.first<b.first;
    return a.second>b.second;
}
int main(){
    cin>>N;
    vector<int> result(N+1, 0);
    input.push_back({-1,-1});
    for(int i=1;i<=N;i++){
        int n; cin>>n;
        input.push_back({n,i});
    }
    for(int i=N;i>0;i--){
        int nowIndex=input[i].second;
        int nowH=input[i].first;
        if(pq.empty()) {
            pq.push(input[i]);
            continue;  
        }
        while(!pq.empty()){
            pair<int,int> next=pq.top();
            //cout<<"현재인덱스 : "<<nowIndex<<" 비교인덱스: "<<next.second<<"\n";
            if(nowH<next.first) break;
            result[next.second]=nowIndex;
            pq.pop();
        }
        pq.push(input[i]);
    }
    for(int i=1;i<=N;i++) cout<<result[i]<<" ";
    return 0;
}