#include <iostream>

using namespace std;
int board[7][7];
int N, M;
int moveY[3] = { 1,1,1 };
int moveX[3] = { -1,0,1 };  //대각왼, 아래, 대각오른
int minWeight = 2000000000;
void dfs(int y, int x, int weight, int lastDirection) {
	if (y > N) {
		if (weight < minWeight) minWeight = weight;
		return;
	}
	weight += board[y][x];
	if (weight > minWeight) return;
	for (int i = 0; i < 3; i++) {
		if (i == lastDirection) continue;
		int nextY = y + moveY[i];
		int nextX = x + moveX[i];
		if (nextX<1 || nextX>M) continue;
		dfs(nextY, nextX, weight, i);
	}
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 1; i <= M; i++) {
		dfs(1, i, 0, -1);
	}
	cout << minWeight;
	return 0;
}