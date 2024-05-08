#include <iostream>
#include <vector>
using namespace std;
int N, M;
vector<int> garosu;
/*
bool sol(int height, vector<bool> visited) {
	for (int i = 0; i < M; i++) {
		int x = garosu[i];
		for (int i = x - height; i < x + height; i++) {
			if (i < 0 || i >= N) continue;
			visited[i] = true;
		}
	}
	for (int i = 0; i < N; i++) {
		if (visited[i] == false) return false;
	}
	return true;
}


	// 모든 위치가 덮여있는지 확인합니다.
	for (int i = 0; i < N; i++) {
		if (!visited[i]) return false;
	}
	return true;
}
*/
bool sol(int height) {
	if ((garosu[0] - height) > 0 || (garosu[M - 1] + height-1) < (N - 1)) return false;
	else return true;
}
int parametric(int left, int right) {
	if (left == right) {
		return left;
	}
	//vector<bool> visited(N, false);
	int mid = (left + right) / 2;
	//if (sol(mid, visited)) return parametric(left, mid);
	if (sol(mid)) return parametric(left, mid);
	else return parametric(mid + 1, right);
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int x; 
		cin >> x;
		garosu.push_back(x);
	}
	int maxHeight = 0;
	for (int i = 0; i < M-1; i++) {
		int minus = garosu[i + 1] - garosu[i];
		int nowHeight;
		if (minus % 2 == 0) nowHeight = minus / 2;
		else nowHeight=((minus / 2) + 1);
		if (maxHeight < nowHeight) maxHeight = nowHeight;
	}
	if (maxHeight == 0) maxHeight = 1;
	int result=parametric(maxHeight, N);
	cout << result;
	return 0;
}