#include <bits/stdc++.h>
using namespace std;
int wall[1001][1001];
bool visited[1001][1001];
int result[1001][1001];
int N, M;
int moveY[4]={0,0,1,-1}; //동서남북
int moveX[4]={1,-1,0,0};  


void bfs(int y, int x){
	int cnt=1;
	vector<pair<int, int> > imsi;
	visited[y][x]=1;
	queue<pair<int, int> > pQ;
	pQ.push({y, x});
	while(!pQ.empty()){

		int nowX=pQ.front().second;
		int nowY=pQ.front().first;
		pQ.pop();
		for(int i=0;i<4;i++){
			int imsiX= nowX+moveX[i];
			int imsiY= nowY+moveY[i];
			if(imsiY>=1&&imsiY<=N&&imsiX<=M&&imsiX>=1){
				if(wall[imsiY][imsiX]==0&&visited[imsiY][imsiX]==0){
					pQ.push({imsiY, imsiX});
					cnt++;
					visited[imsiY][imsiX]=1;

				}
				else if(wall[imsiY][imsiX]!=0&&visited[imsiY][imsiX]==0){
					visited[imsiY][imsiX]=1;
					imsi.push_back({imsiY, imsiX});
				}
			}
		}
		
	}
	for(int i=0;i<imsi.size();i++){
		wall[imsi[i].first][imsi[i].second] += cnt;
		visited[imsi[i].first][imsi[i].second]=0;
	}
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin>>N>>M;
	for(int i=1;i<=N;i++){
		string imsi; cin>>imsi;
		imsi=" "+imsi;
		for(int j=1;j<=M;j++){
			wall[i][j]=imsi[j]-'0';
		}
	}

	//입력받기 종료 
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			if(!wall[i][j]&&!visited[i][j]) bfs(i,j);
		}
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			if(wall[i][j]==0) cout<<"0";
			else cout<<wall[i][j]%10;
		}
		cout<<"\n";
	}

	return 0;
}