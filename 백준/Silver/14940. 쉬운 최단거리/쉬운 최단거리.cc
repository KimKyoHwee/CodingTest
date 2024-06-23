#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int startY, startX;
int moveY[4] = {-1, 0, 1, 0}; // 시계방향
int moveX[4] = {0, 1, 0, -1};

struct Node {
    int y, x, weight;
};

void bfs(vector<vector<int>>& input, vector<vector<int>>& result) {
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    queue<Node> q;

    Node node;
    node.y = startY;
    node.x = startX;
    node.weight = 0;
    q.push(node);
    visited[startY][startX] = true;
    result[startY][startX] = 0;

    while (!q.empty()) {
        Node nowNode = q.front();
        q.pop();
        int nowX = nowNode.x;
        int nowY = nowNode.y;

        for (int i = 0; i < 4; i++) {
            int nextY = nowY + moveY[i];
            int nextX = nowX + moveX[i];

            if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= M || visited[nextY][nextX]) {
                continue;
            }

            if (input[nextY][nextX] == 0) {
                result[nextY][nextX] = 0;
                visited[nextY][nextX] = true;
                continue;
            }

            Node nextNode;
            nextNode.y = nextY;
            nextNode.x = nextX;
            nextNode.weight = nowNode.weight + 1;
            q.push(nextNode);
            visited[nextY][nextX] = true;
            result[nextY][nextX] = nextNode.weight;
        }
    }

    // 도달할 수 없는 위치는 -1로 남겨두기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (input[i][j] == 1 && result[i][j] == -1) {
                result[i][j] = -1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    vector<vector<int>> input(N, vector<int>(M));
    vector<vector<int>> result(N, vector<int>(M, -1));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int n; 
            cin >> n;
            if (n == 2) {
                startY = i;
                startX = j;
            }
            input[i][j] = n;
            if (n == 0) {
                result[i][j] = 0; // 처음부터 갈 수 없는 땅인 경우 0으로 설정
            }
        }
    }

    bfs(input, result);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
