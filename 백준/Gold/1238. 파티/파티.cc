#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int N, M, X;  //노드수, 엣지수, 도착지점
vector<pair<int, int>> edge[1001];  //vector[a]에 {(b,c), (d,e)}있으면 a에서 b까지 c크기 엣지, d까지 e크기엣지 존재
int dist[1001]; //출발노드로부터 각 노드까지의 최단거리

int dijkstra(int start, int end) {
	fill(dist, &dist[N + 1], 2100000000);  //dist 다 최대로 채워놓고
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  
	//<a,b>는 start~b까지 거리가 a인 pair 우선순위큐
	dist[start] = 0;
	pq.push({ 0,start });
	//start노드로 초기화 완료
	while (!pq.empty()) {  //pq에 {start~현재 노드까지 최단거리, 현재 노드번호} 계속입력
		int nowEdge = pq.top().first;  //뽑은 노드까지 최단거리(dist)
		int nowNode = pq.top().second; //뽑은 노드 번호
		pq.pop();
		if (nowNode == end) return nowEdge;
		for (int i = 0; i < edge[nowNode].size(); i++) {  //현재 노드에서 연결된곳 다 가보기
			int nextNode = edge[nowNode][i].first;
			int nextEdge = edge[nowNode][i].second;
			if (dist[nextNode] > (nowEdge + nextEdge)) {
				dist[nextNode] = (nowEdge + nextEdge);
				pq.push({ dist[nextNode], nextNode });
			}
		}
	}

}
int main() {
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge[a].push_back({ b,c });
	}
	int result;
	int maxTime = 0;
	for (int i = 1; i <= N; i++) {
		if (i == X) continue;
		int go = dijkstra(i, X);
		int come = dijkstra(X, i);
		if (maxTime < (go + come)) maxTime = (go + come);
	}
	cout << maxTime;
	return 0;
}