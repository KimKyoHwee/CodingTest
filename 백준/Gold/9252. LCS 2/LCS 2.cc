#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int sI, sJ;
int dp[1001][1001];
int P[1001][1001];  //1은 일치 2는 위로 3은 왼쪽으로 
stack<char> result;

void trace(int i, int j){
	if(i<=0||j<=0) return;
	if(P[i][j]==1){
		result.push(s1[i]);
		trace(i-1, j-1);
	}
	else if(P[i][j]==2){
		trace(i-1, j);
	}
	else trace(i,j-1);
}

int main(){
	cin>>s1>>s2;
	sI=s1.size(); sJ=s2.size();
	s1=" "+s1; s2=" "+s2;
	for(int i=1;i<=sI;i++){
		for(int j=1;j<=sJ;j++){
			if(s1[i]==s2[j]) {
				dp[i][j]=dp[i-1][j-1]+1;
				P[i][j]=1;
				continue;
			}
			dp[i][j]=dp[i-1][j];
			P[i][j]=2;
			if(dp[i][j]<dp[i][j-1]+1){
				dp[i][j]=dp[i][j-1];
				P[i][j]=3;
			}
		}
	}
	cout<<dp[sI][sJ]<<"\n";
	trace(sI, sJ);
	while(!result.empty()){
		cout<<result.top();
		result.pop();
	}
	
	
}