#include <bits/stdc++.h>
using namespace std;

long long N;

long long euler(long long num) {  //오일러 피 함수. N이 소수면 결과는 N-1이므로 long long 반환해야될듯
	long long result = num;
	for (long long i = 2; i*i<= num; i++) {
		if (num % i == 0) {
			result = result / i * (i - 1);
			while (num % i == 0) num /= i;
		}
	}
	if (num != 1) result = result /num* (num - 1);
	return result;
}

int main() {
	cin >> N;
	long long result = euler(N);
	cout << result;
	return 0;
}