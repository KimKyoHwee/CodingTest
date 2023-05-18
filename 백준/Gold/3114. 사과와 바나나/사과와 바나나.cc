#include <bits/stdc++.h>
using namespace std;
int A[1501][1501], B[1501][1501]; 
int aSum[1501][1501], bSum[1501][1501];
int Y,X;
int dp[1501][1501];
int main(){
	cin>>Y>>X;
	for(int i=1;i<=Y;i++){
		for(int j=1;j<=X;j++){
			char c; int n;
			cin>>c>>n;
			A[i][j]=A[i-1][j]+A[i][j-1]-A[i-1][j-1];
			B[i][j]=B[i-1][j]+B[i][j-1]-B[i-1][j-1];
			if(c=='A')	A[i][j]+=n;
			else B[i][j]+=n;		
		}
	}

	//전처리
	for(int i=1;i<=X;i++){  //1행 
		dp[1][i]=A[Y][i]-A[1][i];
	} 
	for(int i=1;i<=Y;i++){  //1열 
		dp[i][1]=A[Y][1]-A[i][1];
	}
	for(int i=2;i<=Y;i++){   //오른쪽, 대각, 아랫방향 3개 가능성 비교 
		for(int j=2;j<=X;j++){
			//오른쪽
			dp[i][j]=max(dp[i][j],dp[i][j-1]+A[Y][j]-A[Y][j-1]+B[i-1][j]-B[i-1][j-1]-(A[i][j]-A[i][j-1])); 
			//대각 
			dp[i][j]=max(dp[i][j],dp[i-1][j-1]+A[Y][j]-A[Y][j-1]+B[i-1][j]-B[i-1][j-1]-(A[i][j]-A[i][j-1]));
			//아래
			dp[i][j]=max(dp[i][j],dp[i-1][j]-(A[i][j]-A[i-1][j]-A[i][j-1]+A[i-1][j-1])); 
		}
	}
	cout<<dp[Y][X];
	return 0;
}