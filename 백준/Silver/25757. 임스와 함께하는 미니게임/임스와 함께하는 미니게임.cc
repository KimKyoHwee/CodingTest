#include <set>
#include <iostream>
using namespace std;

set<string> ss;
int main() {
	int N;
	char G;
	cin >> N >> G;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		ss.insert(s);
	}
	if (G == 'Y') cout << ss.size();
	else if (G == 'F') cout << ss.size() / 2;
	else cout << ss.size() / 3;
	return 0;
}