#include<bits/stdc++.h>
using namespace std;

int N;
vector<int> result;

bool check(int num) {
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) return false;
	}
	return true;
}

void dfs(int num, int cnt) {
	if (check(num)) {
		if (cnt == N) {  //check 성공, 자릿수 일치 => 통과
			result.push_back(num);
			return;
		}
		for (int i = 1; i <= 9; i++) {
			int nextNum = num * 10 + i;
			dfs(nextNum, cnt + 1);
		}
	}
	else return;
}

int main() {
	cin >> N;
	for (int i = 2; i <= 9; i++) dfs(i, 1);
	for (int i = 0; i < result.size(); i++) cout << result[i] << "\n";
	return 0;
}