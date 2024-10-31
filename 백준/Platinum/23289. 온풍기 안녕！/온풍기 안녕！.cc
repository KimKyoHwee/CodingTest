#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int R, C, K, W;
int board[22][22];
int wall[22][22][4]; // 각 좌표의 벽 정보: 0=동, 1=서, 2=남, 3=북
vector<pair<int, int>> checkPoints, rightW, leftW, downW, upW;

// 동서남북 방향
const int dy[4] = {0, 0, 1, -1};
const int dx[4] = {1, -1, 0, 0};

// 바람 전파 함수 - 각 온풍기마다 `visited` 배열 추가
void rightWind(int depth, int y, int x, bool visited[22][22]) {
    if (y < 1 || y > R || x < 1 || x > C || visited[y][x]) return;
    visited[y][x] = true;
    board[y][x] += depth;
    if (depth == 1) return;
    if (!wall[y][x][3] && !wall[y-1][x][0]) rightWind(depth-1, y-1, x+1, visited); // 오른쪽 위
    if (!wall[y][x][0]) rightWind(depth-1, y, x+1, visited);                       // 오른쪽
    if (!wall[y][x][2] && !wall[y+1][x][0]) rightWind(depth-1, y+1, x+1, visited); // 오른쪽 아래
}

void leftWind(int depth, int y, int x, bool visited[22][22]) {
    if (y < 1 || y > R || x < 1 || x > C || visited[y][x]) return;
    visited[y][x] = true;
    board[y][x] += depth;
    if (depth == 1) return;
    if (!wall[y][x][3] && !wall[y-1][x][1]) leftWind(depth-1, y-1, x-1, visited); // 왼쪽 위
    if (!wall[y][x][1]) leftWind(depth-1, y, x-1, visited);                       // 왼쪽
    if (!wall[y][x][2] && !wall[y+1][x][1]) leftWind(depth-1, y+1, x-1, visited); // 왼쪽 아래
}

void downWind(int depth, int y, int x, bool visited[22][22]) {
    if (y < 1 || y > R || x < 1 || x > C || visited[y][x]) return;
    visited[y][x] = true;
    board[y][x] += depth;
    if (depth == 1) return;
    if (!wall[y][x][1] && !wall[y][x-1][2]) downWind(depth-1, y+1, x-1, visited); // 왼쪽 아래
    if (!wall[y][x][2]) downWind(depth-1, y+1, x, visited);                       // 아래
    if (!wall[y][x][0] && !wall[y][x+1][2]) downWind(depth-1, y+1, x+1, visited); // 오른쪽 아래
}

void upWind(int depth, int y, int x, bool visited[22][22]) {
    if (y < 1 || y > R || x < 1 || x > C || visited[y][x]) return;
    visited[y][x] = true;
    board[y][x] += depth;
    if (depth == 1) return;
    if (!wall[y][x][1] && !wall[y][x-1][3]) upWind(depth-1, y-1, x-1, visited); // 왼쪽 위
    if (!wall[y][x][3]) upWind(depth-1, y-1, x, visited);                       // 위
    if (!wall[y][x][0] && !wall[y][x+1][3]) upWind(depth-1, y-1, x+1, visited); // 오른쪽 위
}

// 각 방향별로 온풍기 작동 함수 호출 - `visited` 배열 초기화
void partOne() {
    for (auto &p : rightW) {
        bool visited[22][22] = {false}; // 새로운 visited 배열 생성
        rightWind(5, p.first, p.second + 1, visited);
    }
    for (auto &p : leftW) {
        bool visited[22][22] = {false};
        leftWind(5, p.first, p.second - 1, visited);
    }
    for (auto &p : downW) {
        bool visited[22][22] = {false};
        downWind(5, p.first + 1, p.second, visited);
    }
    for (auto &p : upW) {
        bool visited[22][22] = {false};
        upWind(5, p.first - 1, p.second, visited);
    }
}


void partTwo() {
    int change[22][22] = {0}; // 각 칸의 온도 변화량을 기록하는 배열
    
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            // 동쪽으로 온도 조절
            if (j < C && !wall[i][j][0]) { 
                int diff = abs(board[i][j] - board[i][j + 1]) / 4;
                if (board[i][j] > board[i][j + 1]) {
                    change[i][j] -= diff;
                    change[i][j + 1] += diff;
                } else {
                    change[i][j] += diff;
                    change[i][j + 1] -= diff;
                }
            }
            // 남쪽으로 온도 조절
            if (i < R && !wall[i][j][2]) { 
                int diff = abs(board[i][j] - board[i + 1][j]) / 4;
                if (board[i][j] > board[i + 1][j]) {
                    change[i][j] -= diff;
                    change[i + 1][j] += diff;
                } else {
                    change[i][j] += diff;
                    change[i + 1][j] -= diff;
                }
            }
        }
    }

    // 모든 변화량을 보드에 반영
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            board[i][j] += change[i][j];
        }
    }
}

void partThree() {
    // 왼쪽과 오른쪽 가장자리
    for (int i = 2; i < R; i++) {
        if (board[i][1] > 0) board[i][1]--;
        if (board[i][C] > 0) board[i][C]--;
    }

    // 윗변과 아랫변
    for (int j = 1; j <= C; j++) {
        if (board[1][j] > 0) board[1][j]--;
        if (board[R][j] > 0) board[R][j]--;
    }
}


bool judge() {
    for (auto &p : checkPoints) {
        if (board[p.first][p.second] < K) return false;
    }
    return true;
}

int main() {
    cin >> R >> C >> K;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            int num;
            cin >> num;
            if (num == 1) rightW.push_back({i, j});
            else if (num == 2) leftW.push_back({i, j});
            else if (num == 3) upW.push_back({i, j});
            else if (num == 4) downW.push_back({i, j});
            else if (num == 5) checkPoints.push_back({i, j});
        }
    }

    cin >> W;
    for (int i = 0; i < W; i++) {
        int y, x, num;
        cin >> y >> x >> num;
        if (num == 0) { // 북쪽으로 벽
            wall[y][x][3] = 1;
            wall[y-1][x][2] = 1;
        } else { // 동쪽으로 벽
            wall[y][x][0] = 1;
            wall[y][x+1][1] = 1;
        }
    }

    int choco = 0;
    while (true) {
        partOne();  // 모든 온풍기에서 바람 한번씩 나옴
        partTwo();  // 온도조절
        partThree(); // 온도 1이상 가장 바깥쪽 칸 1씩 감소
        choco++;
        if (choco > 100 || judge()) break;
    }
    cout << choco << "\n";
    return 0;
}
