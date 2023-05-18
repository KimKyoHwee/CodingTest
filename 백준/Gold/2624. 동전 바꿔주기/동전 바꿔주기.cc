#include <bits/stdc++.h>
using namespace std;

int money[1000001];
int K;
vector<pair<int, int> > coin;
int N;

int main(){
	coin.push_back({-1, -1});
	cin>>N>>K;
	for(int i=1;i<=K;i++){
		int a, b; cin>>a>>b;
		coin.push_back({a, b});
	}
	money[0]=1;
	for(int i=1;i<=K;i++){
		for(int j=N;j>0;j--){
			for(int k=1;k<=coin[i].second;k++){
				if(j-coin[i].first*k<0) continue;
				money[j]+=money[j-coin[i].first*k];
			}
			
			
		}
	}
	cout<<money[N]<<"\n";
	return 0;
}