#include <iostream>
#include <queue>
#include <utility>
#include <set>
using namespace std;
int N,K;
struct cmp{
    bool operator()(pair<int, int> p1, pair<int, int> p2){
        if(p1.first==p2.first) return p1.second<p2.second;
        else return p1.first>p2.first;
    }
};
set<int> input;
int answer=-1;
int main(){
    cin>>N>>K;
    for(int i=0;i<N;i++){
        int n; cin>>n;
        input.insert(n);
    }
    vector<bool> visited(K+1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    for(int num:input) {
        if(num>K) continue;
        pq.push({1,num});
        visited[num]=true;
    }
    while(!pq.empty()){
        pair<int, int> nowP=pq.top();
        pq.pop();
        int nowWeight=nowP.first;
        int nowNum=nowP.second;
        //cout<<nowNum<<", ";
        if(nowNum==K){
            answer=nowWeight;
            break;
        }
        for(int num:input){
            if(visited[nowNum+num]) continue;
            if(nowNum+num<=K){
                pq.push({nowWeight+1, nowNum+num});
                visited[nowNum+num]=true;
            }
        }
    }
    cout<<answer;
    
    return 0;
}