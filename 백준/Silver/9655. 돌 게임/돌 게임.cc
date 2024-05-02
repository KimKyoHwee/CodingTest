#include <vector>
using namespace std;
vector<int> dp;   //0 : SK 1: CY
int N;
#include <iostream>
int main() {
	dp.push_back(1);
	dp.push_back(0);  //dp[1]
	dp.push_back(1);  //dp[2]
	cin >> N;
	for (int i = 3; i <= N; i++) {
		if (dp[i - 3] == 0) dp.push_back(1);
		else dp.push_back(0);
	}
	if (dp[N] == 0) cout << "SK";
	else cout << "CY";
	return 0;
}