#include <bits/stdc++.h>
using namespace std;
bool go(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
	else return false;
}

int main() {
	LABEL:while (true) {
		int sum = 0, a = 0, b = 0; //모음갯수, 연속모음갯수, 연속자음갯수
		string s; cin >> s;
		char prev ='NULL';        //이전꺼와 비교할때는 prev사용
		if (s == "end") return 0;
		for (int i = 0; i < s.size(); i++) {
			char now = s[i];
			if (now == prev) {
				if (now != 'e' && now != 'o') {
					cout << "<" << s << "> is not acceptable.\n";
					goto LABEL;
				}
			}
			prev = now;
			if (go(now)) {
				sum++;
				a++; b = 0;
				if (a == 3) {
					cout << "<" << s << "> is not acceptable.\n";
					goto LABEL;
				}
			}
			if(!go(now)) {
				a = 0; b++;
				if (b == 3) {
					cout << "<" << s << "> is not acceptable.\n";
					goto LABEL;
				}
			}
		}
		if (sum < 1) {
			cout << "<" << s << "> is not acceptable.\n";
			goto LABEL;
		}
		cout << "<" << s << "> is acceptable.\n";
	}
	return 0;
}