#include <iostream>
#include <vector>
int dp[10001];
using namespace std;
int N;
int alphaCount(int n){
    int cnt=0;
    for(int i=0;i<=(n/3);i++){
        int nMinusThree=n-(3*i);
        if (nMinusThree%2==0) cnt++;
    }
    return cnt;
}
int main(){
    cin>>N;
    vector<int> input(N);
    dp[1]=1; dp[2]=2; dp[3]=3; dp[4]=4;
    int maxN=0;
    for(int i=0;i<N;i++){
        cin>>input[i];
        if(maxN<input[i]) maxN=input[i];
    }
    for(int i=5;i<=maxN;i++){
        dp[i]=dp[i-1]+alphaCount(i);
        //cout<<i<<": "<<dp[i]<<"\n";
    }
    for(int i=0;i<N;i++) cout<<dp[input[i]]<<"\n";
    return 0;
}