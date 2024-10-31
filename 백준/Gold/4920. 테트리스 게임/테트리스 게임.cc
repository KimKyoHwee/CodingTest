#include <iostream>
#include <vector>
using namespace std;
vector<int> result;
int main(){
    while(1){
        int answer=-987654321;
        int N; cin>>N;
        if(N==0) break;
        vector<vector<int>> board(N, vector<int>(N,0));
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++) cin>>board[i][j];
        }
        int rotate=4;
        while(rotate--){
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    int resultA=-987654321, resultB=-987654321, resultC=-987654321, resultD=-987654321, resultE=-987654321;
                    if(j+3<N) resultA=board[i][j]+board[i][j+1]+board[i][j+2]+board[i][j+3];
                    if(i+1<N&&j+2<N) resultB=board[i][j]+board[i][j+1]+board[i+1][j+1]+board[i+1][j+2];
                    if(i+1<N&&j+2<N) resultC=board[i][j]+board[i][j+1]+board[i][j+2]+board[i+1][j+2];
                    if(j+2<N&&i+1<N) resultD=board[i][j]+board[i][j+1]+board[i][j+2]+board[i+1][j+1];
                    if(i+1<N&&j+1<N) resultE=board[i][j]+board[i][j+1]+board[i+1][j]+board[i+1][j+1];
                    answer=max(answer, resultA);
                    answer=max(answer, resultB);
                    answer=max(answer, resultC);
                    answer=max(answer, resultD);
                    answer=max(answer, resultE);
                }
            }
            vector<vector<int>> copyBoard(board);
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    board[j][N-1-i]=copyBoard[i][j];
                }
            }
        }
        result.push_back(answer);
    }
    for(int i=0;i<result.size();i++) cout<<i+1<<". "<<result[i]<<"\n";


    return 0;
    
}