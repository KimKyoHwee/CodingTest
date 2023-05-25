#include<bits/stdc++.h>
using namespace std;

int f[53][53];  //a~Z->a~Z의 flow 
int c[53][53]; //a~Z->a~Z의 capacity 
int N; 
int visited[53];
set<int> iS[53];  //각 노드에서 연결된 노드들 저장용 

int bfs(int source, int sink){
	int result=0;
	while(1){  //source부터 sink까지 path 찾는 단위 while문 
		fill(visited,&visited[53],-1);
		queue<int> iQ;
		iQ.push(source);
		visited[source]=1;
		//cout<<"여기까지됨\n";
		while((visited[sink]==-1)&&(!iQ.empty())){
			int now=iQ.front();
			iQ.pop();
			set<int>::iterator iter;
			for(iter=iS[now].begin();iter!=iS[now].end();iter++){  //now노드에 연결된 노드들 검색 
				int next=*iter;
				if(visited[next]==-1&&(c[now][next]-f[now][next])>0){  //next를 방문안했고, 잔여용량 있으면 
					iQ.push(next);
					visited[next]=now;
				}
				if(next==sink) break;
			}
		}
		if(visited[sink]==-1) break;  //path못찾았으면 break
		int flow=2100000000;  //구한 path에 흘려보낼 유량 
		int now=sink;  //역순환 시작
		while(now!=source){
			int next=visited[now];
			int imsi=c[next][now]-f[next][now];  //흘려보낼수 있는 유량
			if(flow>imsi)flow=imsi;			
			now=next;
		}
		now=sink;
		while(now!=source){
			int next=visited[now];			
			f[next][now]+=flow;
			f[now][next]-=flow;
			now=visited[now];
		}
		result+=flow;
	}
	return result;
}


int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		char imsi1, imsi2;
		int imsi3, imsi4;
		int imsiEdge;
		cin>>imsi1>>imsi2>>imsiEdge;
		if(imsi1>='A'&&imsi1<='Z') imsi3=(int)imsi1-(int)'A'+27;
		else imsi3=(int)imsi1-(int)'a'+1;
		if(imsi2>='A'&&imsi2<='Z') imsi4=(int)imsi2-(int)'A'+27;
		else imsi4=(int)imsi2-(int)'a'+1;
		c[imsi3][imsi4]+=imsiEdge;  //양방향 간선처리(병렬처리 위해 더하기) 
		c[imsi4][imsi3]+=imsiEdge;  //양방향 간선처리(병렬처리 위해 더하기) 
		iS[imsi3].insert(imsi4);   //imsi3에 연결된 노드로 imsi4 추 
		iS[imsi4].insert(imsi3);
	}
	//입력종료 
	cout<<bfs(27,52); 
	
	return 0;
}