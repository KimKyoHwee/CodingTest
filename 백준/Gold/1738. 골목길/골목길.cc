#include<bits/stdc++.h>
using namespace std;

int N,M;
int dist[101], pred[101];  // 가중치, 직전 노드 배열  
vector<pair<int, int> > pV[101];  //pV[a]={b,c}면 a->b 의 가중치는 c  
//queue<int> iQ;  //bellmanford의 SPFA알고리즘용인데 메모리초과 나옴  
vector<int> result;
vector<int> rev[101];  //목적지까지 가는 길에 cycle 검정용 edge역방향 저장 벡터  
bool visited[101];

int main(){
	cin>>N>>M;
	for(int i=0;i<M;i++){
		int A,B,C; 
		cin>>A>>B>>C;
		pV[A].push_back({B,C});
		rev[B].push_back(A);
	}
	//초기입력 끝
	 for(int i=1;i<=N;i++)	dist[i]=-2100000000;  //최댓값 구해야 되므로 inf는 -21억으로 하자  
	 dist[1]=0;  pred[1]=-1;//초기화 끝 
	 
	 fill(visited,&visited[101],false);  //1~N까지 가는 모든 경로 visted true만들기 
	 queue<int> imsi;
	 imsi.push(N);
	 while(!imsi.empty()){
	 	int now=imsi.front();
	 	imsi.pop();
	 	for(int i=0;i<rev[now].size();i++){
	 		int next=rev[now][i];
	 		if(visited[next]==false){
	 			visited[next]=true;
	 			imsi.push(next);
	 		}
		 }
	 }									//종료  
	 
	 //오리지널 방식의 벨만포드
	 for(int i=1;i<=N;i++){
	 	for(int j=1;j<=N;j++){
	 		for(int k=0;k<pV[j].size();k++){
	 			int now=j;
	 			int next=pV[j][k].first;
	 			int edge=pV[j][k].second;
	 			if(dist[next]<dist[now]+edge){
	 				//if(i==N&&next==N){  
	 				if(i==N&&visited[next]){
	 					cout<<-1;
	 					return 0;
					 }
	 				dist[next]=dist[now]+edge;
	 				pred[next]=now;
				 }
			 }
		 }
	 } 
	 /*  벨만포드 Step2의 SPFA알고리즘인데, 메모리 초과인걸로 봐서 큐를 사용하면 안될듯 
	 iQ.push(1);  //source는 1번 인덱스
	 for(int i=1;i<=N;i++){  //N번 반복 이유는 N번째에 negative cycle 있는지 체크하려고   
	 	for(int k=0;k<iQ.size();k++){  // 각 hop마다 큐를 비워야 하므로 큐의 사이즈만큼 for문돌기 
			int index=iQ.front();
			iQ.pop(); 
	 		for(int j=0;j<pV[index].size();j++){  //시작지점에서 출발할 수 있는 edge들 다 돌기  
	 			 int nextNode=pV[index][j].first;  //시작지점에서 연결될 수 있는 인덱스 
	 			 int edge=pV[index][j].second;  //시작지점에서 연결될 edge의 가중치
				 if(dist[nextNode]<dist[index]+edge){  //새로 edge를 연결했을 때 가중치가 더 커짐(최신화) 
				 	if(i==N&&nextNode==N){ //N번째hop에 최신화되면 negative cycle이 있다는 의미이므로 return 
				 		cout<<-1;
				 		return 0;
					 } 
				 	dist[nextNode]=dist[index]+edge;
				 	pred[nextNode]=index;
					iQ.push(nextNode);
				} 
			}
		}
	 } 
	 */
	 /*
	int index;
	while(pred[index]!=-1){
		result.push_back(index);
		index=pred[index];
	}
	for(int i=1;i<=N;i++){
		for(int j=0;j<pV[i].size();j++){
			int now=i;
			int next=pV[i][j].first;
			int edge=pV[i][j].second;
			if(dist[next]<dist[now]+edge){
				for(int k=0;k<result.size();k++){
					if(next==result[k]){
						cout<<-1;
						return 0;
					}
				}
			}
		}
	}
	*/
	int index=N;
	result.push_back(N);
	while(pred[index]!=-1){
		index=pred[index];
		result.push_back(index);
	}
	for(int i=result.size()-1;i>=0;i--) cout<<result[i]<<" ";
	return 0;
}