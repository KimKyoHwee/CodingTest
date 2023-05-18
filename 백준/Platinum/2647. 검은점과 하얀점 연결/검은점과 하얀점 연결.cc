#include <bits/stdc++.h>
using namespace std;

bool stone[101];
pair<int, int> dp[101][101];
int N;
int mark[101][101];
int num;
vector<pair<int, int> > result;
void markFunc(int left, int right){
	if(left>=right) return;
	if(mark[left][right]==0){
		markFunc(left+1, right-1);
		result.push_back({left, right});
		return;
	}
	else {
		markFunc(left, mark[left][right]);
		markFunc(mark[left][right]+1, right);
		return;
	}
}

bool pandan(int i, int j){
	int black=0; int white=0;
	for(int a=i;a<=j;a++){
		if(stone[a]==1) black++;
		else white++;
	}
	return black==white;
}

int main(){
	
	cin>>N;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++) dp[i][j]={1000000000,-1};
	}
	string s; cin>>s;
	s=" "+s;
	for(int i=1;i<=N;i++) stone[i]=s[i]-'0';
	
	for(int i=1;i<=N;i++) dp[i][i]={0,0};
	for(int i=1;i<N;i++){
		if(stone[i]!=stone[i+1]) dp[i][i+1]={3,1};
	}
	for(int diagonal=3;diagonal<N;diagonal+=2){
		for(int i=1;i<=N-diagonal;i++){
			int j=i+diagonal;
			if(!pandan(i,j)) continue;
			if(stone[i]!=stone[j]){
				dp[i][j]={dp[i+1][j-1].first+(dp[i+1][j-1].second+1)*2+j-i, dp[i+1][j-1].second+1};
				mark[i][j]=0;
			}
			for(int k=i+1;k<j;k+=2){
				if(pandan(i,k)&&pandan(k+1,j)){
					if(dp[i][j].first>dp[i][k].first+dp[k+1][j].first){
						dp[i][j]={dp[i][k].first+dp[k+1][j].first, max(dp[i][k].second,dp[k+1][j].second)};
						mark[i][j]=k;
					}
				else continue;
				}
			}
		}
	}
	cout<<dp[1][N].first<<"\n";
	markFunc(1,N);
	sort(result.begin(), result.end());
	for(int i=0;i<result.size();i++){
		cout<<result[i].first<<" "<<result[i].second<<"\n";
	}	
	return 0;
}