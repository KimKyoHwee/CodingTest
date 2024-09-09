#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> dp(n,vector<int>(m,0));
    for(int i=0;i<puddles.size();i++){
        int puddleY=puddles[i][1]-1;
        int puddleX=puddles[i][0]-1;
        dp[puddleY][puddleX]=-1;
    }
    dp[0][0]=1;
    for(int i=1;i<m;i++) {
        if(dp[0][i-1]==-1||dp[0][i]==-1) dp[0][i]=-1;
        else dp[0][i]=1;
    }
    for(int i=1;i<n;i++){
        if(dp[i-1][0]==-1||dp[i][0]==-1) dp[i][0]=-1;
        else dp[i][0]=1;
    }
    
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(dp[i][j]==-1) continue;
            if(dp[i-1][j]!=-1) dp[i][j]+=dp[i-1][j];
            if(dp[i][j-1]!=-1) dp[i][j]+=dp[i][j-1];
            dp[i][j]%=1000000007;
        }
    }
    int answer = dp[n-1][m-1];
    return answer;
}