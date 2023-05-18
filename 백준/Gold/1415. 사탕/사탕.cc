#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int zeroNum = 1;  //0의 갯수 
long long dp[500005];
bool sosu[500005];
vector<pair<int, int> > iV;
int N;  //사탕 갯수
long long result = 0;  //결과
int last;  //벡터의 마지막 인덱스 

void eratos() {                     //에라토스테네스의 채 
	for (int i = 2; i*i<=(500000); i++) {
		if (sosu[i] == false) continue;
		for (int j = i * 2; j <= 500000; j += i) sosu[j] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	sosu[0] = false; sosu[1] = false;
	fill(&sosu[2], &sosu[500000], true);
	cin >> N;
	for (int i = 0; i < N; i++) {   // 모든 사탕 <가격,갯수> 벡터에 입력 
		int n; cin >> n;
		if (n == 0) {
			zeroNum++;     //0은 따로 처리(나중에 한번에 경우의수에 곱해주기) 
			continue;
		}
		int imsi = 0;          // 벡터에 같은 가격의 사탕 정보 있는지 확인 
		if (iV.size()) {  //벡터가 비어있지 않으면, 
			for (int i = 0; i < iV.size(); i++) {  //벡터 한바퀴 돌기 
				if (iV[i].first == n) {   //벡터에 같은 가격의 사탕 정보가 있으면 갯수만 ++ 
					iV[i].second++;
					imsi++;
				}
			}
			if (imsi == 0) iV.push_back({ n,1 });  //벡터 한바퀴 돌면서 같은 가격의 사탕 정보가 없으면 {가격,1} 벡터에 추가 
		}
		else iV.push_back({ n,1 });  //벡터 비어있으면 {가격,1}벡터에 추가 
	}
	eratos();
	//이제 경우의 수 조합해가며 소수인지 체크한다. 
	dp[0] = 1;
	for (auto at : iV) {
		for (int i = 500000; i >= 0; i--) {
			for (int j = 1; j <= at.second; j++) {
				if (i - at.first * j < 0) break;
				dp[i] += dp[i - at.first * j];
			}
		}
	}
	for (int i = 2; i <= 500000; i++) {
		if (sosu[i] == true) result += dp[i];
	}
	cout << result * (zeroNum );
}
