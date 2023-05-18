#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > pV;
vector<int> B;
int N;
int P[100001], LIS[100001];
int cnt=1;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>N;
	pV.push_back({-1,-1});
	B.push_back(-1);
	for(int i=0;i<N;i++){
		int a, b; cin>>a>>b;
		pV.push_back({a,b});
	}
	sort(pV.begin()+1,pV.end());
	for(int i=1;i<=N;i++) B.push_back(pV[i].second);
	//LIS
	fill(LIS, &LIS[100001], 1000000000);
	LIS[0]=-1000000000;
	
	for(int i=1;i<=N;i++){
		int index=upper_bound(LIS, &LIS[N+1], B[i])-LIS;
		if(LIS[index]>B[i]){
			if(cnt<index) cnt=index;
			LIS[index]=B[i];
			P[i]=index;
		}
		else P[i]=-1;
	}
	int result2=cnt;
	stack<int> result;
	
	for(int i=N;i>=1;i--){
		if(P[i]==cnt){
			cnt--;
			continue;
		}
		else result.push(pV[i].first);
	}
	cout<<result.size()<<"\n";
	while(!result.empty()){
		cout<<result.top()<<"\n";
		result.pop();
	}
	
}