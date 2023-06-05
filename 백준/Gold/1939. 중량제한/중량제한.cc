#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<pair<int, int> > pArr[100001];  //pArr[a].{b,c}는 a와b 사이의 다리 가중치가 c
int minE = 2100000000, maxE = 0;  // parametric 의 범위 
int resultA, resultB;  //최종 목표 : resultA에서 resultB로 가기  
bool visited[100001];  //bfs용 

bool promising(int mid) { //bfs  resultA에서 시작해서 넘겨받은 mid(가중치)로 resultB까지 갈수 있는지   
	fill(&visited[0], &visited[100001], 0);
	visited[resultA] = true; //resultA에서 시작
	queue<int> iQ;
	iQ.push(resultA);
	while (!iQ.empty()) {
		int node = iQ.front();
		iQ.pop();
		if (node == resultB) {  //resultB에 도착했을 경우 
			return true;
		}
		for (int i = 0; i < pArr[node].size(); i++) {  //queue에서 뽑은 노드에서 갈수 있는 곳 다 가보기 
			int nextN = pArr[node][i].first;  //갈 곳 노드 
			int edgeN = pArr[node][i].second;  //갈 곳과 연결된 edge가중치
			if (mid <= edgeN && (!visited[nextN])) {  //edge가 허용 가능범위고, 방문하지 않은 노드라면 queue에 다음 노드 넣기 
				iQ.push(nextN);
				visited[nextN] = true;
			}
		}
	}
	return false;
}

int parametric(int miny, int maxy) {
	if (miny == maxy) return miny;
	int mid = (miny + maxy) / 2;
	if (promising(mid)) {
		if (maxy - miny == 1) {
			if (promising(maxy))return maxy;
			else return miny;
		}
		return parametric(mid, maxy);
	}
	else {
		return parametric(miny, mid - 1);
	}

}

int main() {
	
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		if (C > maxE) maxE = C;
		if (C < minE) minE = C;
		pArr[A].push_back({ B,C });
		pArr[B].push_back({ A,C });
	}
	cin >> resultA >> resultB;
	//초기 입력 끝 
	cout<<parametric(0, maxE);
	return 0;
}