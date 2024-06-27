#include <iostream>
#include <vector>
using namespace std;
int N,D;
struct Road{
    int start, end, len;
};
/*
bool cmp(Road a, Road b){
    return a.end<b.end;
}
*/
int main(){
    cin>>N>>D;
    vector<Road> rV;
    vector<int> dp(D+1);
    for(int i=0;i<N;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(c>=(b-a)) continue;
        Road road;
        road.start=a;
        road.end=b;
        road.len=c;
        rV.push_back(road);
    }
    //sort(rV.begin(), rV.end(), cmp); //지름길 vector를 도착지가 작은 순부터 sort
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=D;i++){
        dp[i]=dp[i-1]+1;
        for(int j=0;j<rV.size();j++){
            if(i==rV[j].end){
                int compLen=dp[rV[j].start]+rV[j].len;
                if((dp[i])>compLen) dp[i]=compLen;
            }
        }
    }
    cout<<dp[D];
    return 0;
}