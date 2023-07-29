#include<bits/stdc++.h>
using namespace std;

int V, E, start;
vector<pair<int,int> > graph[20001];
int result[20001];
//bool visited[20001];
int nearest[20001];

/*  우선순위 큐(힙) 사용 안하면 시간초과
void DS() {
	for (int i = 1; i <= V; i++) {
		result[i] = (i == start) ? 0 : 2100000000;
		nearest[i] = start;
		visited[i] = false; // 방문 배열 초기화
	}
	for (int i = 0; i < graph[start].size(); i++) {
		int end2 = graph[start][i].first;
		int weight2 = graph[start][i].second;
		result[end2] = weight2;
	}
	visited[start] = true;
	//초기화 끝
	int next, now = start;  //다익스트라에서 현재점과 다음점
	for (int i = 0; i < V-1; i++) {
		int max = 2147000000;
		for (int j = 1; j <= V; j++) {  //start부터의 거리가 가장 짧은놈 구하기
			if (visited[j]) continue;
			if (result[j] < max) {
				next = j;
				max = result[j];
			}
		}
		visited[next] = true;  //방문점 찾았고
		nearest[next] = now;  //연결처리 해주고
		for (int j = 0; j < graph[next].size(); j++) { //방문점 거쳐서 거리 짧아지는놈 있으면 처리해주자
			int end2 = graph[next][j].first;
			int weight2 = graph[next][j].second;
			if (result[end2] > result[next] + weight2) {
				result[end2] = result[next] + weight2;
				nearest[end2] = next;
			}
		}
		now = next;  //이건 그냥 연결점 처리용 여기선 필요없을듯?
	}
}
*/
void DS() {
	priority_queue<pair<int, int>,vector<pair<int,int>>, greater<pair<int, int> > > pQ;
	for (int i = 1; i <= V; i++) {
		result[i] = (i == start) ? 0 : 2100000000;
		nearest[i] = start;
	}
	nearest[start] = -1;
	//초기화 끝
	pQ.push({ 0,start });
	while (!pQ.empty()) {
		int now = pQ.top().second;
		int weight = pQ.top().first;
		pQ.pop();
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;  //갈수 있는 곳들
			int weight2 = graph[now][i].second;  // now->next의 가중치
			if (result[next] > weight2 + weight) {   //출발점~now->next가 출발점->next보다 작으면,
				nearest[next] = now;
				result[next] = weight2 + weight;
				pQ.push({ result[next], next });
			}
		}
	}
	
}


int main() {
	cin >> V >> E>>start;
	for (int i = 0; i < E; i++) {
		int imsi1, imsi2, imsi3;  //1->2로 3의 가중치
		cin >> imsi1 >> imsi2 >> imsi3;
		graph[imsi1].push_back({ imsi2, imsi3 });
	}
	//입력 끝
	DS();
	for (int i = 1; i <= V; i++) {
		if (result[i] > 2000000000) cout << "INF" << "\n";
		else cout << result[i] << "\n";
	}
	return 0;
}