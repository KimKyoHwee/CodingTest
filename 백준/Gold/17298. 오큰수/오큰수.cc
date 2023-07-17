#include<bits/stdc++.h>
using namespace std;

stack<int> iS; //오른쪽에서 왼쪽으로 긁어가면서 
int iA[1000001], result[1000001], N;
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> iA[i];
	result[N] = -1; iS.push(iA[N]);  //초기화. 제일 오른쪽 정수 처리
	for (int i = N - 1; i >= 1; i--) {
		while (!iS.empty()) {
			if (iA[i] < iS.top()) {
				result[i] = iS.top(); //자기한테 가장 가까운 큰 수 찾음
				break;
			}
			else iS.pop();  //자기보다 작은 수는 pop
		}
		iS.push(iA[i]);
		if (result[i] == 0) result[i] = -1;
	}
	for (int i = 1; i <= N; i++) cout << result[i] << " ";
	return 0;
}