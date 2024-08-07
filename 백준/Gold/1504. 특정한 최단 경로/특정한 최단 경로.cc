#include <iostream>
#include <vector>
#include <queue>
#include <climits> // INT_MAX 사용을 위한 헤더 파일

using namespace std;

struct Edge {
    int to, weight;
};

int N, E, mustA, mustB;
vector<vector<Edge>> edges;

vector<int> dijkstra(int start) {
    vector<int> dist(N + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int currentDist = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        if (currentDist > dist[currentNode]) continue;

        for (const Edge& edge : edges[currentNode]) {
            int nextNode = edge.to;
            int nextDist = currentDist + edge.weight;

            if (nextDist < dist[nextNode]) {
                dist[nextNode] = nextDist;
                pq.push({nextDist, nextNode});
            }
        }
    }

    return dist;
}

int main() {
    cin >> N >> E;
    edges.resize(N + 1);

    for (int i = 0; i < E; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }
    cin >> mustA >> mustB;

    vector<int> distFrom1 = dijkstra(1);
    vector<int> distFromA = dijkstra(mustA);
    vector<int> distFromB = dijkstra(mustB);

    // 각각의 경로가 존재하지 않는 경우 INT_MAX로 설정되므로 이를 체크해야 합니다.
    int path1 = distFrom1[mustA] != INT_MAX && distFromA[mustB] != INT_MAX && distFromB[N] != INT_MAX ? 
                distFrom1[mustA] + distFromA[mustB] + distFromB[N] : INT_MAX;
 
    int path2 = distFrom1[mustB] != INT_MAX && distFromB[mustA] != INT_MAX && distFromA[N] != INT_MAX ? 
                distFrom1[mustB] + distFromB[mustA] + distFromA[N] : INT_MAX;

    int result = min(path1, path2);
    if (result == INT_MAX) {
        cout << -1;
    } else {
        cout << result;
    }

    return 0;
}
