#include <iostream>
#include <vector>
using namespace std;
int N;
int main() {
	cin >> N;
	vector<int> cards;
	for (int i = 1; i <= N; i++) cards.push_back(i);
	int index = 0;
	for (int i = 1; i <= N; i++) {
		if (i == N) break;
		cards.push_back(cards[index + 1]);
		index += 2;
	}
	cout << cards[index];
	return 0;
}