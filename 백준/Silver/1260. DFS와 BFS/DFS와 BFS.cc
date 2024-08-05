#include<bits/stdc++.h>
using namespace std;

int N, M, V;
vector<int> graph[1001];
vector<int> result;
bool visited[1001];

void dfs(int num) {
	result.push_back(num);
	visited[num] = true;
	for (int i = 0; i < graph[num].size(); i++) {
		int next = graph[num][i];
		if (!visited[next]) dfs(next);
	}
}

void bfs(int num) {
	queue<int> iQ;
	iQ.push(num);
	result.push_back(num);
	while (!iQ.empty()) {
		int now = iQ.front();
		iQ.pop();
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i];
			if (!visited[next]) {
				iQ.push(next);
				visited[next] = true;
				result.push_back(next);
			}
		}
	}
}

int main() {
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a); //양방향
	}
	for (int i = 1; i <= N; i++) // 각 정점의 인접 리스트를 정렬
		sort(graph[i].begin(), graph[i].end());
	fill(visited, &visited[1001], false); //dfs초기화
	dfs(V);
	for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
	cout << "\n"; 
	result.clear();
	fill(visited, &visited[1001], false); visited[V] = true;  //bfs 초기화
	bfs(V);
	for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
	return 0;
}