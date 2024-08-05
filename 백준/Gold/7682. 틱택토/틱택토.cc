#include <iostream>
#include <vector>
using namespace std;
int N, oCnt, xCnt;
int oWinR, xWinR, oWinC, xWinC, xWin, oWin;
vector<string> inputs, results;
void setting(){
    oWin=0;
    xWin=0;
    oWinR=0;
    xWinR=0;
    oWinC=0;
    xWinC=0;
    oCnt=0;
    xCnt=0;
}
int main(){
    string input;
    while(1){
        cin>>input;
        if(input=="end") break;
        inputs.push_back(input);
        N++;
    }
    for(int i=0;i<N;i++){
        setting();
        string board=inputs[i];
        for(int i=0;i<3;i++){
            if(board[i]=='X'&&board[i+3]=='X'&&board[i+6]=='X') xWinC++;
            if(board[i]=='O'&&board[i+3]=='O'&&board[i+6]=='O') oWinC++;
            if(board[i*3]=='X'&&board[i*3+1]=='X'&&board[i*3+2]=='X') xWinR++;
            if(board[i*3]=='O'&&board[i*3+1]=='O'&&board[i*3+2]=='O') oWinR++;
        }
        if(board[0]=='X'&&board[4]=='X'&&board[8]=='X') xWin++;
        else if(board[2]=='X'&&board[4]=='X'&&board[6]=='X') xWin++;
        if(board[0]=='O'&&board[4]=='O'&&board[8]=='O') oWin++;
        else if(board[2]=='O'&&board[4]=='O'&&board[6]=='O') oWin++;
    
        for(int i=0;i<9;i++){
            if(board[i]=='X') xCnt++;
            else if(board[i]=='O') oCnt++;
        }
        if(oWin&&xWin) {
            //cout<<1<<"\n";
            results.push_back("invalid");
            continue;
        }
        else if(oWin==1||oWinR==1||oWinC==1) {
            if(xCnt==oCnt&&oCnt<5) {
                //cout<<2<<"\n";
                results.push_back("valid");
                continue;
            }
        }
        else if(xWin==1||xWinR==1||xWinC==1){
            if(xCnt==(oCnt+1)) {
                //cout<<3<<"\n";
                results.push_back("valid");
                continue;
            }
        }
        else if(!xWin&&!oWin&&xCnt==5&&oCnt==4){
            results.push_back("valid");
            continue;
        }
        //cout<<4<<"\n";
        //cout<<board<<" "<<xWin<<" "<<oWin<<" "<<xCnt<<" "<<oCnt<<"\n";
        results.push_back("invalid");
    }
    for(int i=0;i<N;i++) cout<<results[i]<<"\n";
    return 0;
}