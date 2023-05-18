#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > pV[10001];
int N,M,K;
long long dp[10001][21];  //1번노드에서 i번 노드까지 가는데 j번 도로 포장했을 때 최솟값  

struct Node{
	int A; //현재 위치
	int B; //지금까지 포장한 도로 갯수
	long long C; // 현재까지 가중치  
	bool operator < (const Node& second)const{
		return C > second.C;  //우선순위 큐 만들 때 오름차순으로 만들기  
	}
};

priority_queue<Node> pQ;  //구조체 우선순위 큐(가중치 작은게 우선순위) 

void DS(int index){  //다익스트라
	for(int i=0;i<=N;i++){  //초기화  
		for(int j=0;j<=20;j++) dp[i][j]=9223372036854775800; 
	}
	Node imsi;
	imsi.A=1; imsi.B=0; imsi.C=0;   
	dp[1][0]=0;
	pQ.push(imsi);  //시작 노드 넣기 
	while(!pQ.empty()){
		Node imsi2=pQ.top();  //imsi2의 A는 현재 지점, B는 현재 포장한 도로 수, C는 현재까지 가중치 합 
		pQ.pop();
		if(dp[imsi2.A][imsi2.B]<imsi2.C) continue;  //뽑은거까지 가는 방법 중 이미 더 빠른거 있으면 패스  
		for(int i=0;i<pV[imsi2.A].size();i++){  //현재 위치 imsi2.A에서 갈 수 있는 edge 다 추가 
			int nextA=pV[imsi2.A][i].first;
			long long nextC=imsi2.C+pV[imsi2.A][i].second;
			if(nextC<dp[nextA][imsi2.B]){  //다음에 도착하는 곳까지 포장 안하고 감 
				Node imsi3;
				imsi3.A=nextA; imsi3.B=imsi2.B; imsi3.C=nextC;  
				pQ.push(imsi3);
				dp[nextA][imsi2.B]=nextC;
			}
			if(K>imsi2.B&&imsi2.C<dp[nextA][imsi2.B+1]){  //다음에 도착하는 곳까지 포장 하고 감 
				Node imsi4;
				imsi4.A=nextA; imsi4.B=imsi2.B+1; imsi4.C=imsi2.C;
				pQ.push(imsi4);
				dp[nextA][imsi2.B+1]=imsi2.C; 
			}
		}
	}
}

int main(){
	cin>>N>>M>>K;
	for(int i=0;i<M;i++){
		int a, b, c;
		cin>>a>>b>>c;
		pV[a].push_back({b,c});
		pV[b].push_back({a,c});
	}
	DS(1);
	long long result=9223372036854775800; 
	for(int i=0;i<=K;i++){
		if(result>dp[N][i]) result=dp[N][i];
	}
	cout<<result;
	return 0;
}