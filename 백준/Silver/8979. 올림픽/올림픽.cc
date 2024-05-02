#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, K;
int kgold, ksilver, kbronze;

struct Country {
	int index;
	int gold;
	int silver;
	int bronze;
};

bool cmp(Country a, Country b) {
	if (a.gold == b.gold && a.silver == b.silver) return a.bronze > b.bronze;
	else if(a.gold == b.gold && a.silver != b.silver) return a.silver > b.silver;
	else return a.gold > b.gold;
}
int main() {
	vector<Country> cv;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int a, b, c, d;  cin >> a >> b >> c >> d;
		Country ct;
		ct.index = a;
		ct.gold = b;
		ct.silver = c;
		ct.bronze = d;
		cv.push_back(ct);
		if (a == K) {
			kgold = b;
			ksilver = c;
			kbronze = d;
		}
	}
	sort(cv.begin(), cv.end(), cmp);
	for (int i = 0; i < K; i++) {
		Country ct = cv[i];
		if (kgold == ct.gold && ksilver == ct.silver && kbronze == ct.bronze) {
			cout << i+1<<"\n";
			break;
		}
	}
	return 0;
}