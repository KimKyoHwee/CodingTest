#include <bits/stdc++.h>
using namespace std;

int R,C;  //첫 입력받는 R C 크기의 배열 
vector<pair<int, int> > car, place;  //차 위치랑 주차장 위치 
char cA[51][51];  //공간 입력받기 
long long visited[51][51];  //visited[y][x]는 각 car가 그곳까지 가는데 걸리는 시간
long long timeArr[101][101];  //time[a][b]는 a번쨰 car가 b번째 주차장까지 가는데 걸리는 시간 
vector<int> connect[101];  //connect[a][b]는 a번째 car가 b번째 주차장까지 도달할 수 있다는 뜻 
int moveX[4]={1,-1,0,0};  //동서남북
int moveY[4]={0,0,-1,1}; //동서남북 
int result=0;  //결과 

bool visited2[101];  //Bipartite Matching용 
int match[101]; // Bipartite Matching용  

void bfs(int y, int x, int carNum){  //각 차별로 차의 위치와 차 번호 받아서 각 차부터 각 주차장까지의 거리 저자유 
	queue<pair<int, int> > imsiQ;
	imsiQ.push({y,x});
	visited[y][x]=0; //시작점(차가 위치한 곳)
	while(!imsiQ.empty()){
		pair<int, int> imsi;
		imsi=imsiQ.front();
		imsiQ.pop();
		for(int i=0;i<4;i++){
			int imsiX=imsi.second+moveX[i];
			int imsiY=imsi.first+moveY[i];
			if(imsiX>=0&&imsiX<C&&imsiY>=0&&imsiY<R){
				if(cA[imsiY][imsiX]!='X'&&visited[imsiY][imsiX]==-1){
					visited[imsiY][imsiX]=visited[imsi.first][imsi.second]+1; //이전보다 1만큼 더 움직여서 현재에 옴
					imsiQ.push({imsiY,imsiX}); 
				} 
			}
		}
	} 
	//bfs종료  visited배열이 초기화 될 것이므로 이 car이 주차장까지 걸리는 시간을 따로 저장해야됨  
	for(int i=0;i<place.size();i++){
		if(visited[place[i].first][place[i].second]==-1) timeArr[place[i].first][place[i].second]=2100000000;  //차가 도달하지 못하는 주차장
		else{
			connect[carNum].push_back(i);  //차가 주차장에 도달했음  
			timeArr[carNum][i]=visited[place[i].first][place[i].second];
		}
	} 
}

bool dfs(int carNum, int mid){  //parametric에서 넘겨준 값의 이하로 차들을 주차장에 옮길 수 있는지 
	if(visited2[carNum]) return false;
	visited2[carNum]=true;
	for(int i=0;i<connect[carNum].size();i++){  //탐색하고자 하는 car가 갈 수 있는 주차장들 connect[carNum][i] 탐색  
		int imsi=connect[carNum][i];  //탐색중이 car이 갈 수 있는 주차장 번호들 임시저장 
		if(timeArr[carNum][imsi]>mid) continue;  //갈 수 있는 주차장중 가는 시간이 mid 넘으면 그 주차장은 배제
		if(match[imsi]==-1||dfs(match[imsi],mid)){  //갈 수 있는 주차장중 빈 곳이 있거나, 그 주차장에 있는 다른 차량이 다른 주차장에 갈 수 있으면 
			match[imsi]=carNum;
			return true;
		} 
	}
	return false;
}

int parametric(int left, int right){  //Bipartite Matching 사용  
	if(left==R*C) return -1;  // 최소후보~최대후보 모두 FALSE(주차 못하는 차량 생김)일시 -1출력해야함  
	if(left>=right) return left;
	int mid=(left+right)/2;
	int ans=0;
	fill(match, &match[101], -1);
	for(int i=0;i<car.size();i++){  //모든 차량 순회하면서  
		fill(visited2, &visited2[101], false);  
		if(dfs(i,mid)) ans++;  //해당 차량이 시간 내에 주차할 수 있으면 주차 가능 차량 +1 
	}
	if(ans==car.size()){  //mid값으로 모든 차량 주차 가능  
		return parametric(left, mid);
	}
	else return parametric(mid+1, right);
}

int main(){
	cin>>R>>C;
	for(int i=0;i<R;i++){
		string imsi; cin>>imsi;
		for(int j=0;j<C;j++){
			cA[i][j]=imsi[j];
			if(imsi[j]=='C') car.push_back({i,j});
			if(imsi[j]=='P') place.push_back({i,j});
		}
	} 
	for(int i=0;i<car.size();i++){
		fill(&visited[0][0],&visited[R][C],-1); //visited배열 각 car마다 초기화
		bfs(car[i].first,car[i].second,i); 
	}
	result=parametric(0,R*C);  //0~R*C까지 parametric
	
	if(car.size()==0) cout<<0; 
	else if(car.size()>place.size()) cout<<-1;  //오류. 차가 주차장보다 많으면 -1출력 (다 주차 불가능) 
	else cout<<result;	
	return 0;
}