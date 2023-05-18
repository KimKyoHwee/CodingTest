#include <bits/stdc++.h>
using namespace std;

int sdoku[10][10];

bool promising(int y, int x, int value){

	//가로, 세로, 3X3 칸 체크  
	for(int i=1;i<=9;i++){  //가로체크 
		if(i==x) continue;
		if(value==sdoku[y][i]) return false;
	}
	for(int i=1;i<=9;i++){  //세로체크 
		if(i==y) continue;
		if(value==sdoku[i][x]) return false;
	}
	int startY = (y-1)/3*3+1;
	int startX = (x-1)/3*3+1;
	for(int i=startY;i<=startY+2;i++){
		for(int j=startX;j<=startX+2;j++){
			if(i==y&&j==x) continue;
			if(value==sdoku[i][j]) return false;
		}
	}
	return true;
}

bool track(int y, int x){
	if(x == 10){ // 열의 인덱스가 10이 되면 다음 행으로 넘어감
		return track(y+1, 1);
	}
	if(y == 10){ // 마지막 행까지 다 도달했으면 종료
		return true;
	}
	if(sdoku[y][x] != 0){ // 현재 위치에 이미 숫자가 있으면 다음 위치 탐색
		return track(y, x+1);
	}
	for(int i=1;i<=9;i++){
		if(promising(y,x,i)){
			sdoku[y][x]=i;
			if(track(y,x+1)){ // 다음 위치가 맞게 채워진 경우 종료
				return true;
			}
			sdoku[y][x]=0; // 다음 위치가 맞지 않게 채워진 경우 현재 위치를 0으로 초기화
		}
	}
	return false; // 다음 위치에 어떤 숫자를 채워도 답을 찾을 수 없는 경우
}

int main(){
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			int imsi; cin>>imsi;
			sdoku[i][j]=imsi;
		}
	}
	if(track(1,1)){ // 백트래킹 함수가 true를 반환했으면 정답이 존재하는 것
		for(int i=1;i<=9;i++){
			for(int j=1;j<=9;j++){
				cout<<sdoku[i][j]<<" ";
			}
			cout<<"\n";
		}
	}
	return 0;
}