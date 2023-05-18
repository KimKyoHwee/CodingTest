#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, long long> iP;  //typedef사용법   
vector<iP> pV;  //기둥들 y값의 오름차순으로 정렬한 벡터 
int N;
stack<iP> p;  //볼록껍질 알고리즘 사용 배열  (후입선출) 
int result = 0;

bool compareP(iP a, iP b) {  //y값의 오름차순으로 정렬 (y값 같으면 x값 작은것 먼저) 
	if (a.second < b.second) return true;
	else if (a.second == b.second) {
		if (a.first < b.first) return true;
		else return false;
	}
	else return false;
}

long long graham(iP a, iP b, iP c) {
	return a.first * b.second + b.first * c.second + c.first * a.second - (b.first * a.second + c.first * b.second + a.first * c.second);
}


bool compare(iP a, iP b) {  //p[0]과의 각도 오름차순 정렬 (p[0], a, b의 외적 사용) 
	long long imsi = graham(pV[0], a, b);
	if (imsi) return imsi > 0;   //외적값이 양수면 a,b,c가 반시계방향 >> a와 b의 각도가 a와 c의 각도보다 작다. 
	else if (a.second != b.second) return a.second < b.second;  //두개의 각도 같으면 y값 작은거먼저, 같으면 x작은거 먼저
	else return a.first < b.first;
}

int main() {
	long long imsiA, imsiB;
	cin >> N>>imsiA>>imsiB;
	iP prison={imsiA, imsiB};
	for (int i = 0; i < N; i++) {
		long long a, b; cin >> a >> b;
		pV.push_back({ a, b });
		
	}
	
	while (pV.size() >= 3) {		
		sort(pV.begin(), pV.end(), compareP);
		//입력받은 기둥들 y값이 작은것 기준으로 정렬 완료

		vector<iP> iV;
		//볼록껍질 알고리즘 시작  
		sort(pV.begin() + 1, pV.end(), compare);  //0과 1번인덱스 제외 초기화(각도로)
		p.push(pV[0]);
		p.push(pV[1]);
		
		for (int i = 2; i < pV.size(); i++) {  //i<pV.size 지켜보기

			while (p.size() >= 2) {  //2개 아래로 내려가면 새로운 점 검정 불가
				iP b = p.top();
				p.pop();
				iP a = p.top();
				if (graham(a, b, pV[i]) > 0) {
					p.push(b);
					break;
				}
				else iV.push_back(b);
				
			}
			p.push(pV[i]);
		}
		vector<iP> pp;
		
		while (!p.empty()) {
			pp.push_back(p.top());
			p.pop();
		} //p 스택 clear됨
		if (pp.size() >= 3) {
			int same;
			if (graham(prison, pp[0], pp[1]) > 0) same = 1;
			else same = -1;
			for (int i = 0; i <= pp.size() - 2; i++) {
				int imsiSame;
				if (graham(prison, pp[i], pp[i + 1]) > 0) imsiSame = 0;
				else if (graham(prison, pp[i], pp[i + 1]) == 0) {
					same = 0;
					break;
				}
				else imsiSame = -1;
				if (same != imsiSame) {
					same = 0;
					break;
				}
			}
			if (same != 0) result++;
		}
		
		pV.swap(iV);
	}
	cout << result;
	return 0;
}