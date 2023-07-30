#include <bits/stdc++.h>
using namespace std;

int N, M;
int root[201];

int findRoot(int node) {
	if (root[node] == node) return node;
	else return findRoot(root[node]);
}

void mergeSet(int first, int second) {
	root[findRoot(second)] = findRoot(first);
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) root[i] = i;  //union-find 초기화

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int imsi; cin >> imsi;
			if (imsi) {
				mergeSet(i, j);
			}
		}
	}

	int start; cin >> start;  //출발점 입력받고
	for (int i = 0; i < M - 1; i++) {
		int imsi; cin >> imsi;
		if (findRoot(start) != findRoot(imsi)) {
			cout << "NO" << "\n";
			return 0;
		}
	}
	cout << "YES" << "\n";
	return 0;
}