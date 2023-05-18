#include <bits/stdc++.h>
using namespace std;

int N,M,C;
#define mod 1000007
int dp[51][51][51][51];
int game[51][51];

int main(){
	cin>>N>>M>>C;
	for(int i=1;i<=C;i++){
		int a,b; cin>>a>>b;
		game[a][b]=i;
	}
	
	if(game[1][1]) dp[1][1][1][game[1][1]]=1;
	else dp[1][1][0][0]=1;
	
	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			if(i==1&&j==1) continue;
			if(game[i][j]){
				for(int k=0;k<game[i][j];k++){
					for(int l=0;l<=k;l++){
						dp[i][j][l+1][game[i][j]]+=dp[i-1][j][l][k];
						dp[i][j][l+1][game[i][j]]+=dp[i][j-1][l][k];
						dp[i][j][l+1][game[i][j]]%=mod;
					}
				}
			}
			else{
				for(int k=0;k<=C;k++){
					for(int l=0;l<=k;l++){
						dp[i][j][l][k]+=dp[i-1][j][l][k];
						dp[i][j][l][k]+=dp[i][j-1][l][k];
						dp[i][j][l][k]%=mod;
					}
				}
			}
		}
	}
	for(int i=0;i<=C;i++){
		int sum=0;
		for(int j=0;j<=C;j++){
			sum+=dp[N][M][i][j];
		}
		cout<<sum%mod<<" ";
	}
	return 0;
} 