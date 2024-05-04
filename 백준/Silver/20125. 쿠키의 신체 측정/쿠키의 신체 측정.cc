#include <iostream>
using namespace std;
int N;
char board[1001][1001];
int headY, headX;
int leftArm, rightArm, center, leftLeg, rightLeg;
int main() {
	cin >> N;
	bool flag = true;
	for (int i = 1; i <= N; i++) {
		string s; cin >> s;
		for (int j = 0; j < N; j++) {
			board[i][j + 1] = s[j];
			if (flag && board[i][j+1] == '*') {
				headY = i;
				headX = j+1;
				flag = false;
			}
		}
	}
	//왼팔
	for (int i = headX - 1; i>=1; i--) {
		if (board[headY + 1][i] == '*') leftArm++;
		else break;
	}
	//오른팔
	for (int i = headX + 1; i <= N; i++) {
		if (board[headY + 1][i] == '*') rightArm++;
		else break;
	}
	//허리
	for (int i = headY + 2; i <= N; i++) {
		if (board[i][headX] == '*') center++;
		else break;
	}
	//왼다리
	for (int i = headY + 2 + center; i <= N; i++) {
		if (board[i][headX - 1] == '*') leftLeg++;
		else break;
	}
	//오른다리
	for (int i = headY + 2 + center; i <= N; i++) {
		if (board[i][headX + 1] == '*') rightLeg++;
		else break;
	}
	cout <<headY+1<<" "<<headX<<"\n"<< leftArm << " " << rightArm << " " << center << " " << leftLeg << " " << rightLeg;
	return 0;
}
