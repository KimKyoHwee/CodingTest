#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <deque>
using namespace std;
int T,K;
string W;
vector<pair<int, int>> result;
int main(){
    cin>>T;
    while(T--){
        int minR=1000000000, maxR=-1;
        map<char, vector<int>> index;  //해당 알파벳의 인덱스 저장
        map<char, int> cnt; //해당 알파벳의 갯수 저장
        cin>>W;
        cin>>K;
        for(int i=0;i<W.size();i++){  
            char c=W[i];
            cnt[c]++;
            index[c].push_back(i);
        }
        for(pair<char, vector<int>> p:index){
            char c=p.first;
            if(cnt[c]<K) continue;
            for(int j=0;j<(cnt[c]-K+1);j++){
                int len=index[c][j+K-1]-index[c][j]+1;
                minR=min(len, minR);
                maxR=max(len,maxR);
            }
        }
        result.push_back({minR, maxR});
    }
    for(int i=0;i<result.size();i++){
        int a=result[i].first;
        int b=result[i].second;
        if(a==1000000000||b==-1) cout<<-1<<"\n";
        else cout<<a<<" "<<b<<"\n";
    }
    return  0;
}