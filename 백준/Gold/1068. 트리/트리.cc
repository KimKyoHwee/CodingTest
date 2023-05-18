#include <bits/stdc++.h>
using namespace std;
vector<int> iV[54];
int num, root,del;
int dfs(int here) {
	int child = 0; int result = 0;
	for (int there : iV[here]) {
		if (there == del) continue;   //삭제해야되는 부분에 접근시 continue로 접근무시
		result += dfs(there);
		child++;
	}
	if (child == 0) return 1;
	return result;
}

int main() {
	cin >> num;
	for (int i = 0; i < num; i++) {
		int n; cin >> n;
		if (n == -1) root = i;
		else {
			iV[n].push_back(i);  //이러면 n이겹치면(0이 2개 들어가는 상황)
			                         //vector에 어떤식으로 저장이 되는건가요?
			                         //iV[0]으로 접근하면 값이 어떻게 저장되어있는지 모르겠습니다.
			                         //iV[0]에 체인형식으로 엮여져있는건가요??
		}
	}
	cin >> del;
	if (del == root) {
		cout << 0;
		return 0;
	}
	else cout << dfs(root);
	return 0;
}