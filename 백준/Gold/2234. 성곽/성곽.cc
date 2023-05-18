#include<bits/stdc++.h>
using namespace std;

int N,M;
int wall[51][51];  //입력받는 기본배열 
bool visited[51][51];  //방문여부 (visit으로 만드니까 ambiguous뜸 visited로 만들자) 
int moveY[4]={0,-1,0,1};  //서북동남 순으로 해야 비트연산 가능 
int moveX[4]={-1,0,1,0}; 
int result1, result2, result3;


int bfs(int y,int x){  //y,x에서 시작한 도형 넓이 반환 
	queue<pair<int, int> > pQ;  // {y,x} pair 큐 
	pQ.push({y,x});
	visited[y][x]=1;
	int imsi=1;  //넓이 출력하려고  
	while(!pQ.empty()){
		int nextY=pQ.front().first;
		int nextX=pQ.front().second;
		pQ.pop();
		for(int i=0;i<4;i++){
			int imsiY=nextY+moveY[i];
			int imsiX=nextX+moveX[i];
			if(imsiY>0&&imsiY<=M&&imsiX>0&&imsiX<=N){
			
				if(visited[imsiY][imsiX]==0&&( (wall[nextY][nextX]&(1<<i) ) )==0){ //이동할곳이 방문하지 않았고, 그 방향에 벽이 없으면 
					imsi++;
					pQ.push({imsiY,imsiX});
					visited[imsiY][imsiX]=1;
				}
			}
		}
	}
	return imsi;
}

int main(){
	cin>>N>>M;
	for(int i=1;i<=M;i++){
		for(int j=1;j<=N;j++){
			int imsi; cin>>imsi;
			wall[i][j]=imsi;
		}
	}
	for(int i=1;i<=M;i++){
		for(int j=1;j<=N;j++){
			if(visited[i][j]==0){
				result1++;
				int imsi=bfs(i,j);
				if(imsi>result2) result2=imsi;
			} 
		}
	}
	cout<<result1<<"\n"<<result2<<"\n";
	
	
	//이제 result3구해야됨 
	for(int i=1;i<=M;i++){
		for(int j=1;j<=N;j++){
			for(int k=1;k<=8;k<<=1){
				if(wall[i][j]&k){  //i,j 에 벽이 있으면,  
					wall[i][j]-=k;  //벽 허물고
					fill(&visited[1][1], &visited[50][51], 0);  //visit 비워주고 
					int imsi=bfs(i,j);
					if(imsi>result3) result3=imsi;
					wall[i][j]+=k; //벽원복 
				}
			}
		}
	} 
	cout<<result3;
	return 0;
} 