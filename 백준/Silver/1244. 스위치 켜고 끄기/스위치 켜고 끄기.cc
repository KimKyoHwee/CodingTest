#include <iostream>
int switches[101], N,M;
using namespace std;
void switchClick(int index) {
	if (switches[index] == 0) switches[index] = 1;
	else switches[index] = 0;
}
void boy(int num) {
	for (int i = num; i <= N; i += num) switchClick(i);
}
void girl(int num) {
	switchClick(num);
	int spread = 1;
	while (1) {
		int right = num + spread, left = num - spread;
		if (right > N || left < 1) break;
		if (switches[right] == switches[left]) {
			switchClick(left);
			switchClick(right);
			spread++;
		}
		else break;
	}
}
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> switches[i];
	cin >> M;
	for (int i = 0; i < M; i++) {
		int sex, switchNum; cin >> sex>>switchNum;
		if (sex == 1) boy(switchNum);
		else girl(switchNum);
	}
	for (int i = 1; i <= N; i++) {
		if (i != 1 && (i % 20 == 1)) cout << "\n";
		cout << switches[i] << " ";
	}
	return 0;
}