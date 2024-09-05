#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int solution(int N, int number) {
    if (N == number) return 1; // N이 number와 같으면 N 한 번 사용

    vector<set<int>> dp(9); // N을 i번 사용하여 만들 수 있는 수를 저장할 set, 최대 8번 사용

    // N을 i번 반복하여 만든 수 (ex: 5, 55, 555, ...)
    int temp = N;
    for (int i = 1; i <= 8; i++) {
        dp[i].insert(temp);
        temp = temp * 10 + N; // N을 이어붙여서 만든 숫자
    }

    // 2번부터 8번까지 DP를 채워 나감
    for (int i = 2; i <= 8; i++) {
        // N을 j번 사용한 결과와 N을 i-j번 사용한 결과를 조합하여 i번 사용한 결과를 만듦
        for (int j = 1; j < i; j++) {
            for (int a : dp[j]) {
                for (int b : dp[i - j]) {
                    dp[i].insert(a + b);
                    dp[i].insert(a - b);
                    dp[i].insert(a * b);
                    if (b != 0) dp[i].insert(a / b);
                }
            }
        }

        // 만약 dp[i]에 number가 있다면 i번 사용하여 number를 만들 수 있음
        if (dp[i].count(number)) return i;
    }

    // 8번 사용했는데도 만들 수 없으면 -1 리턴
    return -1;
}
