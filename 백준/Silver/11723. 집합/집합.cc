#include <set>
#include <iostream>
using namespace std;

int N;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	string oper;
	int opNum;
	int bit = 0;
	while (N--) {
		cin >> oper;
		if (oper == "add") {
			cin >> opNum;
			bit |= (1 << opNum);
		}
		else if (oper == "remove") {
			cin >> opNum;
			bit &= (~(1 << opNum));
		}
		else if (oper == "check") {
			cin >> opNum;
			if (bit & (1 << opNum)) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (oper == "toggle") {
			cin >> opNum;
			bit ^= (1 << opNum);
		}
		else if (oper == "all") {
			bit = (1 << 21) - 1;
		}
		else if (oper == "empty") {
			bit = 0;
		}
	}
	return 0;
}