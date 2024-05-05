#include <iostream>
#include <algorithm>
using namespace std;
int N, P, newScore, scores[51], result, sameCnt;

int main() {
	cin >> N >> newScore >> P;
	if (N == 0) {
		cout << 1;
		return 0;
	}
	scores[0] = 2147483600;
	for (int i = 1; i <= N; i++) cin >> scores[i];
	for (int i = 1; i <= N; i++) {
		if (scores[i] <= newScore) {
			result = i;
			break;
		}
	}
	if (result == 0) result = N + 1;
	for (int i = result; i <= N; i++) {
		if (scores[i] == newScore) sameCnt++;
		else break;
	}
	if ((result + sameCnt) > P) {
		cout << -1;
		return 0;
	}
	else cout << result;
	return 0;
}