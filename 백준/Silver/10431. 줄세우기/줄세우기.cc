#include <iostream>
#include <algorithm>
using namespace std;
int arr[20], P;
int result[1001];
int main() {
	cin >> P;
	for (int i = 1; i <= P; i++) {
		fill(arr, &arr[20], 0);
		int resultNum;
		cin >> resultNum;
		int sum = 0;
		for (int j = 0; j < 20; j++) {
			int num; cin >> num;
			bool flag = true;
			for (int k = 0; k < j; k++) {
				if (arr[k] > num) {
					flag = false;
					for (int x = j-1; x >= k; x--) {  //제일뒤에서부터 한칸씩미루기
						arr[x + 1] = arr[x];
						sum++;
					}
					arr[k] = num;
					break;
				}
			}
			if (flag) arr[j] = num;
		}
		result[resultNum] = sum;
	}
	for (int i = 1; i <= P; i++) {
		cout << i << " " << result[i] << "\n";
	}
	return 0;
}