#include <bits/stdc++.h>
using namespace std;

int N,M;
int wall[51][51];
bool visited[51][51];
int moveY[4]={0,-1,0,1};  //서북동남 
int moveX[4]={-1,0,1,0}; 

int bfs(int y, int x){
	int cnt=0;
	queue<pair<int, int> > pQ;
	pQ.push({y,x});
	
	while(!pQ.empty()){
		pair<int, int> imsi=pQ.front();
		pQ.pop();
		cnt++;
		int nowY=imsi.first;  int nowX=imsi.second;
		visited[y][x]=1;
		for(int i=0;i<4;i++){
			int nextY=nowY+moveY[i];
			int nextX=nowX+moveX[i];
			if(nextX>=1&&nextX<=M&&nextY>=1&&nextY<=N){
				if(visited[nextY][nextX]==false&&((wall[nowY][nowX]&(1<<i)))==0){
					visited[nextY][nextX]=1;
					pQ.push({nextY, nextX});
				}
			}
		}
	}
	//cout<<"cnt : "<<cnt<<"\n";
	return cnt;
}


int main(){
	int result1=0;
	int result2=0;
	int result3=0;
	cin>>M>>N;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			int imsi; cin>>imsi;
			wall[i][j]=imsi;
		}
	}
	fill(&visited[0][0], &visited[51][51], false);
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			if(visited[i][j]==false){
				result1++;
				int imsi=bfs(i,j);
				if(imsi>result2) result2=imsi;
				
			}
		}
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			for(int k=1;k<=8;k<<=1){
				if(wall[i][j]&k){
					wall[i][j]-=k;
					fill(&visited[0][0], &visited[51][51], false);
					int imsi=bfs(i,j);
					if(result3<imsi) result3=imsi;
					wall[i][j]+=k;
				}
			}
		}
	}
	cout<<result1<<"\n"<<result2<<"\n"<<result3;
	return 0;
}