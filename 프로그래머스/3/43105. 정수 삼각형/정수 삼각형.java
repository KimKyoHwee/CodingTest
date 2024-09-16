class Solution {
    public int solution(int[][] triangle) {
        int N = triangle.length;
        int[][] dp = new int[N][N];  // 고정 크기 배열을 사용하여 DP 테이블 생성

        // 첫 번째 값 초기화
        dp[0][0] = triangle[0][0];

        // DP 테이블 채우기
        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j <= i; j++) {
                // 왼쪽 아래로 내려가는 경우
                dp[i + 1][j] = Math.max(dp[i + 1][j], dp[i][j] + triangle[i + 1][j]);
                // 오른쪽 아래로 내려가는 경우
                dp[i + 1][j + 1] = Math.max(dp[i + 1][j + 1], dp[i][j] + triangle[i + 1][j + 1]);
            }
        }

        // 마지막 줄에서 최댓값 찾기
        int answer = 0;
        for (int i = 0; i < N; i++) {
            answer = Math.max(answer, dp[N - 1][i]);
        }

        return answer;
    }
}
