#include <bits/stdc++.h>
using namespace std;
int m, n;
int iArr[104][104];
int visited[104][104];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
vector<int> result;

void go(int y, int x) {
	visited[y][x] = 1;
	if (iArr[y][x] == 1) {
		iArr[y][x] = 0; 
		return;
	}
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i]; int yy = y + dy[i];
		if (xx<0 || xx>n - 1 || yy<0 || y>m - 1) continue;
		if (visited[yy][xx] == 0) go(yy, xx);
	}
	return;
}

int solve() {
	int sum = 0;
	fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (iArr[i][j] == 1) sum++;
		}
	}
	go(0, 0);
	return sum;
}
int main() {
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> iArr[i][j];
		}
	}
	while (true) {
		int n = solve();
		if (n == 0) break;
		else result.push_back(n);
	}
	int last;
	sort(result.begin(), result.end());
	cout << result.size() << "\n" << result[0];
	return 0;
}