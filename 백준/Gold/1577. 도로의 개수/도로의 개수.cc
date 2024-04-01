#include <iostream>
#include <algorithm>
using namespace std;

long long dp[101][101];
bool breakUnder[101][101]={false};  //i,j기준 아래쪽에서 못오면 1(true)
bool breakLeft[101][101] = { false };  //i,j기준 왼쪽에서 못오면 1(true)
int N, M, K;
int main() {
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if ((c - a) == 1) breakLeft[d][c] = true;
		if ((a - c) == 1) breakLeft[b][a] = true;
		if ((d - b) == 1) breakUnder[d][c] = true; 
		if ((b - d) == 1)breakUnder[b][a] = true;
	}
	dp[0][0] = 1;  //초기화
	for (int i = 1; i <= M; i++) { //세로 0열 초기화
		if (breakUnder[i][0]||dp[i-1][0]==-1) dp[i][0] = -1;
		else dp[i][0] += dp[i - 1][0];
	}
	for (int i = 1; i <= N; i++) {  //가로 0행 초기화
 		if (breakLeft[0][i]|| dp[0][i-1] == -1) dp[0][i] = -1;
		else dp[0][i] += dp[0][i-1];
	}
	//초기화 종료

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			if (dp[i - 1][j] == -1 || breakUnder[i][j]) {  //아래에서 올 수 없음
				if (dp[i][j - 1] == -1 || breakLeft[i][j]) {  //아래에서 올 수 없고 왼쪽에서도 올 수 없음
					dp[i][j] = -1;
					continue;
				}
				else {  //아래에서 올 수 없지만 왼쪽에서 올 수 있음
					dp[i][j] += dp[i][j - 1];
				}
			}
			else { //아래에서 올 수 있음
				if (dp[i][j - 1] == -1 || breakLeft[i][j]) {  //아래쪽에서 올 수 있으나 왼쪽에서 올 수 없음
					dp[i][j] += dp[i - 1][j];
				}
				else { //양쪽에서 다 올수 있음
					dp[i][j] += (dp[i - 1][j] + dp[i][j - 1]);
				}
			}
		}
	}
	if (dp[M][N] <0) dp[M][N] = 0;
	cout << dp[M][N];
	return 0;
}