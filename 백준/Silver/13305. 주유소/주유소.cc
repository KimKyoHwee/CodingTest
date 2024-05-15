#include <iostream>
#include <vector>
using namespace std;
vector<int> edge, price;
int N;
unsigned long long dp[100001];
int main() {
	cin >> N;
	edge.push_back(-1); price.push_back(-1); //[0]번 쓰레기값으로 채우기
	for (int i = 0; i < (N - 1); i++) {
		int num; cin >> num;
		edge.push_back(num);
	}
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		price.push_back(num);
	}
	dp[1] = 0;
	int cheapNode, cheapPrice = price[1];
	for (int i = 2; i <= N; i++) {
		if (price[i - 1] < cheapPrice) cheapPrice = price[i - 1];  //다음 인덱스로 가기 전, 이전 인덱스까지 가장 저렴한 가격의 기름 저장
		dp[i] = (unsigned long long)dp[i - 1] + (unsigned long long)((unsigned long long)cheapPrice * edge[i - 1]);
	}
	cout << dp[N];
	return 0;
}