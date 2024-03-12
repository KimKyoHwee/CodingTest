/*
#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
//전역변수
int N; //N x N 정사각 보드
stack<int> basket; //바구니
int answer = 0;
//전역변수 끝
void pushDallToBasket(int doll){  //바구니에 인형넣기
    if(doll==basket.top()){
        basket.pop();
        answer+=2;
    }
    else basket.push(doll);
}
int solution(vector<vector<int>> board, vector<int> moves) {
    basket.push(-5);
    N=board[0].size();
    for(int i=0;i<moves.size();i++){
        int doll=0; //뽑을 인형
        int col=moves[i]-1; //보드는 0행0열부터 시작하므로 1빼주기
        for(int j=0;j<N;j++){ //col열의 0행~n-1행까지 돌면서 제일 위에꺼 찾기
            if(board[j][col]==0) continue;  //비어있으면 다음행으로 이동
            doll=board[j][col]; //인형 뽑음
            board[j][col]=0; //뽑았으니까 지우기
        }
        pushDallToBasket(doll);
    }
    return answer;
    
}
*/
#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int N; // N x N 정사각 보드
stack<int> basket; // 바구니
int answer = 0;

// 바구니에 인형 넣기
void pushDollToBasket(int doll) {
    if (!basket.empty() && doll == basket.top()) {
        basket.pop();
        answer += 2;
    } else {
        basket.push(doll);
    }
}

int solution(vector<vector<int>> board, vector<int> moves) {
    basket.push(-5); // 비어있는지 확인하는 용도로 -5를 넣어둠
    N = board.size();

    for (int i = 0; i < moves.size(); i++) {
        int col = moves[i] - 1; // 보드는 0행 0열부터 시작하므로 1을 빼줌

        for (int j = 0; j < N; j++) {
            if (board[j][col] != 0) { // 인형이 있는 경우
                pushDollToBasket(board[j][col]); // 바구니에 넣기
                board[j][col] = 0; // 인형을 뽑았으므로 해당 칸은 비워줌
                break;
            }
        }
    }
    
    return answer;
}
