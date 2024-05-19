#include <iostream>
#include <vector>
using namespace std;
int N, K;
vector<bool> isPerson;
vector<bool> visited;
int main() {
	cin >> N >> K;
	string input;
	cin >> input;
	for (int i = 0; i < N; i++) {
		if (input[i] == 'P') isPerson.push_back(true);
		else {
			isPerson.push_back(false);
		}
		visited.push_back(false);
	}
	int result = 0;
	for (int i = 0; i < N; i++) {
		if (isPerson[i] == true) {
			for (int j = i - K; j <= i + K; j++) {
				if (j < 0 || j >= N) continue;
				else if (isPerson[j] == false && visited[j] == false) {
					result++;
					visited[j] = true;
					break;
				}
			}
		}
	}
	cout << result;
	return 0;
}