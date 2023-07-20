#include<bits/stdc++.h>
using namespace std;
int N, result;
priority_queue<int, vector<int>, greater<int> > pQ;

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int imsi; cin >> imsi;
		pQ.push(imsi);
	}
	while (pQ.size() >= 2) {
		int imsi1 = pQ.top();
		pQ.pop();
		int imsi2 = pQ.top();
		pQ.pop();
		pQ.push(imsi1 + imsi2);
		result = result+imsi1 + imsi2;
	}
	cout << result;
	return 0;
}