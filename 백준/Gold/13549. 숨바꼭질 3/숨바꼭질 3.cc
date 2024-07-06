#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

int N, K;
bool visited[100001] = {false};

int bfs() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, N});
    while (!pq.empty()) {
        pair<int, int> now = pq.top();
        pq.pop();
        int nowSec = now.first;
        int nowPoint = now.second;

        if (nowPoint < 0 || nowPoint > 100000) continue;  // 범위를 벗어나는 경우 무시
        if (visited[nowPoint]) continue;  // 이미 방문한 경우 무시

        visited[nowPoint] = true;

        if (nowPoint == K) return nowSec;

        pq.push({nowSec + 1, nowPoint + 1});
        pq.push({nowSec + 1, nowPoint - 1});
        pq.push({nowSec, nowPoint * 2});
    }
    return -1;  // 이 경우는 발생하지 않음
}

int main() {
    cin >> N >> K;
    cout << bfs();
    return 0;
}
