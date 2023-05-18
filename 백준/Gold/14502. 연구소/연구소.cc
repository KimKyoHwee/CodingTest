#include <bits/stdc++.h>
using namespace std;
int iArr[10][10];    //연구소 행렬
int visited[10][10]; 	int boksa[10][10];
int m, n;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
vector<pair<int, int>> hubo;    //행렬에서 0인것들 다 때려박고 벽세울 3곳 뽑을때 사용
vector<int> result;
vector<int> sumV;

void go(int y, int x) {
	if (boksa[y][x] == 1 || visited[y][x] == 1) return;  //이미 방문했거나 벽이 있으면 접근불가
	visited[y][x] = 1;
	boksa[y][x] = 2;
	for (int i = 0; i < 4; i++) {
		int yy = y + dy[i];  int xx = x + dx[i];
		if (yy<1 || yy>m || xx<1 || x>n) continue;
		go(yy, xx);
	}
	return;
}
int solve() {
	int sum = 0;
	fill(&visited[0][0], &visited[0][0] + 10 * 10, 0);
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			boksa[i][j] = iArr[i][j];
		}
		
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (boksa[i][j] == 2) go(i, j);
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (boksa[i][j] == 0)sum++;
		}
	}
	return sum;
}
int main() {
	cin >> m >> n;
	fill(&visited[0][0], &visited[0][0] + 10 * 10, 0);
	fill(&iArr[0][0], &iArr[0][0] + 10 * 10, 0);
	fill(&boksa[0][0], &boksa[0][0] + 10 * 10, 0);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> iArr[i][j];
			if (iArr[i][j] == 0) hubo.push_back({ i,j });
		}
	}
	int aaa = 0;
	for (int i = 0; i < hubo.size()-2; i++) {  //3개 뽑는 조합일때는 3중첩 for문 사용
		for (int j =i+1; j < hubo.size()-1; j++) {
			for (int k=j+1; k < hubo.size(); k++) {
				aaa++;
				iArr[hubo[i].first][hubo[i].second] = iArr[hubo[j].first][hubo[j].second] = 1;
				iArr[hubo[k].first][hubo[k].second] = 1;
				sumV.push_back(solve());
				iArr[hubo[i].first][hubo[i].second] = iArr[hubo[j].first][hubo[j].second] = 0;
				iArr[hubo[k].first][hubo[k].second] = 0;
			}
		}
	}
	sort(sumV.begin(), sumV.end(), greater<int>());  //오름차순정렬
	cout << sumV[0];
	return 0;
}