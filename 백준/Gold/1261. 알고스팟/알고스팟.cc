#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int N, M;
int moveY[4] = {-1, 1, 0, 0}; // 상하좌우
int moveX[4] = {0, 0, -1, 1};

int main() {
    cin >> M >> N;
    vector<vector<int>> board(N + 1, vector<int>(M + 1, -1));
    for (int i = 1; i <= N; i++) {
        string s; cin >> s;
        for (int j = 1; j <= M; j++) {
            board[i][j] = s[j - 1] - '0';
        }
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; // 벽 부순 갯수, 좌표
    vector<vector<bool>> visited(N + 1, vector<bool>(M + 1, false));
    pq.push({0, {1, 1}});
    visited[1][1] = true;

    while (!pq.empty()) {
        int nowWeight = pq.top().first;
        int nowY = pq.top().second.first;
        int nowX = pq.top().second.second;
        pq.pop();

        // 목표 지점에 도달했을 때
        if (nowY == N && nowX == M) {
            cout << nowWeight;
            return 0;
        }

        // 인접한 노드를 탐색
        for (int i = 0; i < 4; i++) {
            int nextY = nowY + moveY[i];
            int nextX = nowX + moveX[i];

            // 경계 체크와 방문 체크
            if (nextY < 1 || nextY > N || nextX < 1 || nextX > M || visited[nextY][nextX]) continue;

            visited[nextY][nextX] = true;
            if (board[nextY][nextX] == 1) {
                pq.push({nowWeight + 1, {nextY, nextX}});
            } else {
                pq.push({nowWeight, {nextY, nextX}});
            }
        }
    }

    return 0;
}
