#include <iostream>
#include <map>
using namespace std;
map<char, int> base;
string input;
int N;

bool check(map<char, int> base2, int num) {
	int cnt = 0;
	for (auto iter = base.begin(); iter != base.end(); iter++) {
		char c = iter->first;
		if (base2[c] < 0) continue;
		cnt += base2[c];
	}
	if (num == 0) {
		if (cnt == 0 || cnt == 1) return true;
	}
	else if (num == -1) {
		if (cnt == 0) return true;
	}
	else if (num == 1) {
		if (cnt == 1) return true;
	}
	return false;
}
int main() {
	cin >> N;
	cin >> input;
	for (int i = 0; i < input.size(); i++) {
		char c = input[i];
		base[c]++;
	}
	int result = 0;
	for (int i = 1; i < N; i++) {
		map<char, int> base2 = base;
		string s2; cin >> s2;
		for (int j = 0; j < s2.size(); j++) {
			char c = s2[j];
			base2[c]--;
		}
		if (check(base2, input.size() - s2.size())) {
			//cout <<"정답처리 : "<< s2 << "\n";
			result++;
		}
	}
	cout << result;
	return 0;
}