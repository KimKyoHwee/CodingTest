#include <bits/stdc++.h>
using namespace std;

string s; 
int N;
bool pelin[2501][2501];
int dp[2501];
bool pelinCheck(int i, int j) {
	if (j > N) return false;
	if (s[i] == s[j]) {
		if (j - i == 1) return true;  //i~j로 이루어진 문자열이 2글자고, 둘이 같으면 팰린 
	    if(pelin[i+1][j-1]) return true;//pelin 배열 outofbounds주의, 양 끝 문자가 같고, 그 사이의 문자가 팰린이면 그 문자는 팰린 
	}
	return false;  //else return false 하면 오류 왜>> 양끝은 같은데 안에가 팰린드롬이 아닌 경우가 있는데 그것들 리턴이 안됨 
}


int main(){
	cin>>s;
	N=s.size();
	s=" "+s;
	//fill(&pelin[1][1],&pelin[N][N],false);
	
	for(int i=1;i<=N;i++) pelin[i][i]=true;	
	
	
	for(int diagonal=1;diagonal<N;diagonal++){
		for(int i=1;i<=N-diagonal;i++){
			int j=i+diagonal;
			if(diagonal==1||diagonal==2){
				if(s[i]==s[j]) pelin[i][j]=true;
				continue;
			}
			if(s[i]==s[j]&&pelin[i+1][j-1]) pelin[i][j]=true;
			
			//pelin[i][j]=pelinCheck(i,j);
		}
	}
	fill(dp,dp+2501,1000000000);
	dp[0]=0;
	for(int i=1;i<=N;i++){
		for(int k=1;k<=i;k++){
			if(pelin[k][i]&&dp[i]>dp[k-1]+1){
				dp[i]=dp[k-1]+1;
			}
		}
		dp[i]=min(dp[i-1]+1, dp[i]);
	}
	cout<<dp[N];
	return 0;
}