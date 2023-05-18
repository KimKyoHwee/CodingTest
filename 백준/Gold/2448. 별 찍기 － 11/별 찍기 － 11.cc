#include <iostream>
#include <string>
#include <cstring>
#include <cmath>  //루트 구하기(sqrt함수) , log구하기 (log함수) 
#include <algorithm>  //fill
using namespace std;
#define MAX 3072 
char cArr[MAX][2*MAX];  //N이 최대일때 좌표 

void mark(int y,int x){
	cArr[y][x]='*'; cArr[y+1][x-1]='*'; cArr[y+1][x+1]='*';
	for(int i=0;i<5;i++) cArr[y+2][x-2+i]='*';
	return;
}
void rec(int y, int x, int N){
	if(N==3){
		mark(y,x);
		return;
	}
	rec(y,x,N/2);
	rec(y+N/2,x-N/2,N/2);
	rec(y+N/2,x+N/2,N/2);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin>>N;  // N 입력받기  
	fill(&cArr[0][0], &cArr[MAX-1][2*MAX-1],' ');
	rec(0,N-1,N);
	for(int i=0;i<N;i++){
		for(int j=0;j<2*N-1;j++){
			cout<<cArr[i][j];
		}
		cout<<"\n";
	}
}