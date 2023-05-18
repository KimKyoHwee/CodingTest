#include<bits/stdc++.h>
using namespace std;

#define INF 1234567890
#define ll long long

int N, M;
int A[111], S[111];
int dp[111][111];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for(int i=1; i<=N; i++)
	{
		cin >> A[i];
		S[i] = S[i-1] + A[i];
	}
	
	// dp[k][i] : [i,N]에서 k개 만들어야 할 때 sum의 최댓값
	// dp[k][i] = max_{i <= j <= N} (dp[k-1][j+2] + S[j]-S[i-1]) 또는 dp[k][i+1] 
	for(int k=0; k<111; k++)
		for(int i=0; i<111; i++)
			dp[k][i] = -INF;
	
	// base case: 일단 M개 구간을 다 쓰기만 하면 성공이다.  
	for(int i=1; i<=N+2; i++)
		dp[0][i] = 0;
		
	// cal dp
	for(int k=1; k<=M; k++)
		for(int i=N; i>=1; i--)
		{
			dp[k][i] = max(dp[k][i], dp[k][i+1]);
			for(int j=i; j<=N; j++)
				dp[k][i] = max(dp[k][i], dp[k-1][j+2] + S[j]-S[i-1]);
		}
	cout << dp[M][1] << "\n";
	return 0;
}
