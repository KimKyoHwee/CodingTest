#include <iostream>
#include <vector>
using namespace std;
int N,M;
int nowY, nowX, dir, moveY[4]={-1,0,1,0}, moveX[4]={0,1,0,-1};
int main(){
    int answer=0;
    cin>>N>>M;
    cin>>nowY>>nowX>>dir;
    vector<vector<int>> board(N, vector<int>(M,0));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++) cin>>board[i][j];
    }
    while(1){
        if(board[nowY][nowX]==0){
            board[nowY][nowX]=-1;
            answer++;
        }
        bool flag=false; //4칸에 청소할 곳 없음
        for (int i = 0; i < 4; i++) { // 왼쪽으로 4번 회전 시도
            dir = (dir + 3) % 4; // 왼쪽으로 회전
            int nextY=nowY+moveY[dir];
            int nextX=nowX+moveX[dir];
            if(nextY<0||nextY>=N||nextX<0||nextX>=M) continue;
            if(board[nextY][nextX]==0){
                //dir=nowDir;
                flag=true;
                break;
            }
        }
        if(flag){
            nowY+=moveY[dir];
            nowX+=moveX[dir];
            continue;
        }
        else{
            int nextY=nowY-moveY[dir];
            int nextX=nowX-moveX[dir];
            if(nextY<0||nextY>=N||nextX<0||nextX>=M) break;;
            if(board[nextY][nextX]==1) break;
            else{
                nowY=nextY;
                nowX=nextX;
            }
        }
    }
    cout<<answer;


}