#include<bits/stdc++.h>
using namespace std;

#define INF 1234567890
#define ll long long

int T;
int N, K;
ll dp[111][111];

int main()
{
	// dp[k][i] : [1,i]에서 인접한 비트가 k개가 되게 만드는 경우의 수 
	// dp[k][i] = sum_{1 <= j <= i} (dp[k-(i-j)][max(0,j-2)]) 또는 dp[k][i-1] 
		
	dp[0][0] = 1; // base case
	for(int k=0; k<=100; k++)
		for(int i=1; i<=100; i++)
		{
			dp[k][i] += dp[k][i-1]; // 0 놓기 
			for(int j=1; j<=i; j++)
				if (k-(i-j) >= 0)
					dp[k][i] += dp[k-(i-j)][max(0,j-2)]; // 연속한 1을 놓고 0을 놓기 
		}
	
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> N >> K;
		cout << dp[K][N] << "\n";
	}
	return 0;
}
