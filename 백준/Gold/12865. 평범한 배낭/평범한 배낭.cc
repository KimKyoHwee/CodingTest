#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
int N,K;
int main(){
    cin>>N>>K;
    vector<pair<int, int>> items;
    items.push_back({-1,-1}); //0번 아이템은 쓰레기값
    for(int i=0;i<N;i++){
        int W, V; cin>>W>>V;
        items.push_back({W,V});
    }
    vector<vector<int>> dp(N+1, vector<int>(K+1, 0));
    for(int i=1;i<=N;i++){
        for(int j=1;j<=K;j++){
            int itemW=items[i].first;
            int itemV=items[i].second;
            if(j>=itemW){
                dp[i][j]=max(dp[i-1][j], dp[i-1][j-itemW]+itemV);
            }
            else dp[i][j]=dp[i-1][j];
        }
    }
    cout<<dp[N][K];
    return 0;
}