#include <bits/stdc++.h>
using namespace std;

int N;
int head[10001];
pair<int, int> child[10001];
vector<int> iV[10001];
int width=1;
int maxH=0;

int findHead(int idx){
	if(head[idx]==-1) return idx;
	else return findHead(head[idx]);
}

void dfs(int head, int height){
	if(height>maxH) maxH=height;
	if(child[head].first!=-1) dfs(child[head].first, height+1);
	iV[height].push_back(width);
	width++;
	if(child[head].second!=-1) dfs(child[head].second, height+1);
}

int main(){
	fill(head,&head[10001],-1);
	cin>>N;
	for(int i=1;i<=N;i++){
		int a,b,c; cin>>a>>b>>c;
		head[b]=a; head[c]=a;
		child[a]={b,c};
	}
	int head=findHead(1);
	dfs(head, 1);
	int result=0;
	int result2=1;
	for(int i=1; i<=maxH;i++){
		int right=0, left=1000000000;
		for(int j=0;j<iV[i].size();j++){
			if(left>iV[i][j]) left=iV[i][j];
			if(right<iV[i][j]) right=iV[i][j];
		}
		if(result<right-left+1) {
			result=right-left+1;
			result2=i;
		}
	}
	cout<<result2<<" "<<result;
	return 0;
}