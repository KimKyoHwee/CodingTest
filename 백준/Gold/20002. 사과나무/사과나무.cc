#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, answer = -987654321;

int main() {
    cin >> N;
    vector<vector<int>> sum(N+1, vector<int>(N+1, 0)); // 누적합 배열
    vector<vector<int>> input(N+1, vector<int>(N+1, 0));
    
    // 입력과 누적합 계산
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            int n; cin >> n;
            input[i][j] = n;
            answer = max(answer, n); // 가장 큰 값 갱신
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + n; // 2차원 누적합 계산
        }
    }
    
    // 모든 정사각형 구간에 대한 합 계산
    for(int i = 1; i <= N; i++) { // i는 정사각형의 크기
        for(int j = 1; j <= (N - i + 1); j++) { // j는 y (시작 행)
            for(int k = 1; k <= (N - i + 1); k++) { // k는 x (시작 열)
                int lastY = j + i - 1, lastX = k + i - 1;
                int nowSum = sum[lastY][lastX] - sum[j-1][lastX] - sum[lastY][k-1] + sum[j-1][k-1];
                answer = max(answer, nowSum); // 최대 구간합 갱신
            }
        }
    }
    
    cout << answer;
    return 0;
}
