#include <iostream>
#include <string>               // C++ 표준 string 클래스 사용
#include <cstring>              // C 스타일 문자열 라이브러리
#include <utility>
#include <vector>
#define MAX 1000000
using namespace std;

vector <pair<int, int>> nArr[101];
bool sosu[MAX+1];//100만 이하 소수(소수는 true)
int insu[MAX + 1];
int intArr[105];

void primeNum() {   //에라토스테네스의 채
	for (int i = 2; i * i <= MAX; i++) {  //2부터 100만까지 채로 거르기
		if (sosu[i] == false) continue;
		for (int j = 2 * i; j <= MAX; j += i) sosu[j] = false;
	}
}
void insuBunhae(int x, int y) {  //인수분해 함수
	int maximum = x;
	for (int i = 2; i<= x; i++) {	
		int insuNum = 0;
		while (1) {
			if (maximum == 1) break;
			if (sosu[i] == true && maximum % i == 0) {
				maximum /= i;
				insuNum++;
			}
			else {
				break;
			}
		}
		if (insuNum > 0) {
			nArr[y].push_back({ i,insuNum });
		}
	}
}

int main() {
	fill(&sosu[0], &sosu[1000000], true);
	primeNum();
	int nArrNum;
	cin >> nArrNum;
	int n;
	int y = 0;     // nArr[y]는 y번째 입력받은 숫자의 인수분해 결과물
	for (int i = 1; i <= nArrNum; i++) {
		cin >> n;
		intArr[i] = n;
		insuBunhae(n,y);   //숫자 받자마자 인수분해 후 vector에 입력
		y++;
	}
		for (int i = 0; i < nArrNum; i++) {  //각 소인수 갯수 합치기
		for (int j = 0; j < nArr[i].size(); j++) {
			insu[nArr[i][j].first] += nArr[i][j].second;
		}
	}

	int sum = 1;
	for (int i = 2; i <= MAX; i++) {
		
		if (!sosu[i]) continue;
		insu[i] /= nArrNum;
		if (insu[i] >= 1) {
			for (int j = 0; j < insu[i]; j++) sum *= i;
		}
	}


	//nArr[0]번째부터 nArr[nArrNum-1]까지 벡터형으로 인수-지수 페어벡터로 저장됨
	//insu배열에 인수 전체 합 들어가있음
	int operSum = 0;
	int found = 0;
	for (int i = 2; i <= MAX; i++) {
		found = 0;
		if (insu[i] >= 1) { //처리해야할 인수 있으면
	
			for (int j = 0; j < nArrNum; j++) {  //입력받은 숫자 갯수만큼 반복
				found = 0;
				for (int k = 0; k < nArr[j].size(); k++) {  //각 숫자별로 인수 모아놓은 벡터 크기만큼반복
					if (nArr[j][k].first == i) {

						found++;
						if (nArr[j][k].second < insu[i]) {
							operSum += (insu[i] - nArr[j][k].second);
		
						}
					}
				}
				if (found == 0) {
					operSum += insu[i];
				}
			}
		}
	}
	int aa = 1;
	cout << sum << " " << operSum;
	return 0;
}