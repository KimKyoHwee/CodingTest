#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int V, E;
int head[10001];
//int graph[10001][10001];
struct Edge {
	int start, end, weight;
};
vector<Edge> eV;

bool cmp(Edge a, Edge b) {
	return a.weight < b.weight;
}
int findRoot(int vertex) {
	if (head[vertex] == vertex)return vertex;
	else return findRoot(head[vertex]);
}
bool find(Edge edge) {
	if (findRoot(edge.start) == findRoot(edge.end)) return false;
	else return true;
}
void merge(Edge edge) {
	int startRoot = findRoot(edge.start);
	int endRoot = findRoot(edge.end);
	if (startRoot < endRoot) head[endRoot] = startRoot;
	else head[startRoot] = endRoot;
}
int main() {
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int a, b, c; cin >> a >> b >> c;
		head[a] = a; head[b] = b;
		Edge edge;
		edge.start = a;
		edge.end = b;
		edge.weight = c;
		eV.push_back(edge);
	}
	int result = 0;
	sort(eV.begin(), eV.end(), cmp);
	int cnt=0; 
	int i = 0;
	while (1) {
		if (cnt == (V - 1)) break;
		Edge edge = eV[i];
		if (find(edge)) {
			cnt++;
			merge(edge);
			result += edge.weight;
		}
		i++;
	}
	cout << result;
}