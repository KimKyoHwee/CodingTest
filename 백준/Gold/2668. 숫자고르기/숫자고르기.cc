#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
int N;
vector<int> inputs, result;
int main(){
    inputs.push_back(-1); //0번 인덱스 비우기
    cin>>N;
    for(int i=0;i<N;i++){
        int input; cin>>input;
        inputs.push_back(input);
    }
    vector<bool> visited(N+1, false);
    for(int i=1;i<=N;i++){
        if(visited[i]) continue;  //이미 지나간곳이면 무시
        visited[i]=true;
        int now=i;
        unordered_set<int> nowVisit; //이번 인덱스에서 출발해서 지나가는 곳들
        vector<bool> cycleCheck(N+1, false); //이번 사이클 체크에서 지나간 곳들
        cycleCheck[now]=true;
        nowVisit.insert(now);
        while(1){
            int next=inputs[now];
            if(next==i){ //cycle 완성
                nowVisit.insert(next);
                for(auto it=nowVisit.begin();it!=nowVisit.end();it++){
                    result.push_back(*it);
                    visited[*it]=true;
                }
                break;
            }
            if(visited[next]||cycleCheck[next]) break;
            nowVisit.insert(next);
            cycleCheck[next]=true;
            now=next;
        }
    }
    sort(result.begin(), result.end());
    cout<<result.size()<<"\n";
    for(int i=0;i<result.size();i++) cout<<result[i]<<"\n";
    return 0;
}