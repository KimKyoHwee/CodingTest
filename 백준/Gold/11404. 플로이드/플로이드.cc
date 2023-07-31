#include <bits/stdc++.h>
using namespace std;


int N, M;
vector<pair<int, int> > bus[101];
int result[101][101];

int main() {
	cin >> N >> M;
	fill(&result[0][0], &result[100][101], 200000000);
	for (int i = 1; i <= N; i++) result[i][i] = 0;  //초기화
	for (int i = 1; i <= M; i++) {
		int first, second, weight;
		cin >> first >> second >> weight;
		if (result[first][second] > weight) result[first][second] = weight;
	}
	for (int i = 1; i <= N; i++) {  //노드 선택
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (j == i || k == i) continue;
				if (result[j][k] > (result[j][i] + result[i][k])) {
					result[j][k] = result[j][i] + result[i][k];
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (result[i][j] >= 200000000) cout << 0 << " ";
			else cout << result[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
