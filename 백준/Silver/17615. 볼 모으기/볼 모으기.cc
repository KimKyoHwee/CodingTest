#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
int N, result=2100000000, redCnt, blueCnt, nowCnt;
stack<int> redS, blueS;  //빨 우, 파 우
queue<int> redQ, blueQ;  //빨 좌, 파 좌
int main(){
    string input, s;
    cin>>N>>s;
    s=" "+s;
    
    //input
    for(int i=1;i<=N;i++){
        if(s[i]=='R') {
            redCnt++;
            redS.push(i);
            redQ.push(i);
        }
        else {
            blueCnt++;
            blueS.push(i);
            blueQ.push(i);
        }
    }   

    //case 1 빨, 좌
    input=s;
    nowCnt=0;
    for(int i=1;i<=redCnt;i++){
        if(input[i]!='R') {
            nowCnt++;
            int changeIndex=redQ.front();
            redQ.pop();
            input[changeIndex]='B';
        }
        else redQ.pop();
    }
    if(result>nowCnt) result=nowCnt;
    //cout<<nowCnt<<"\n";

    //case 2 빨, 우
    input=s;
    nowCnt=0;
    for(int i=N;i>(N-redCnt);i--){
        if(input[i]!='R') {
            nowCnt++;
            int changeIndex=redS.top();
            redS.pop();
            input[changeIndex]='B';
        }
        else redS.pop();
    }
    if(result>nowCnt) result=nowCnt;
    //cout<<nowCnt<<"\n";

    //case 3 파, 좌
    input=s;
    nowCnt=0;
    for(int i=1;i<=blueCnt;i++){
        if(input[i]!='B'){
            nowCnt++;
            int changeIndex=blueQ.front();
            blueQ.pop();
            input[changeIndex]='R';
        }
        else blueQ.pop();
    }
    if(result>nowCnt) result=nowCnt;
    //cout<<nowCnt<<"\n";

    //case 4 파, 우
    input=s;
    nowCnt=0;
    for(int i=N;i>(N-blueCnt);i--){
        if(input[i]!='B'){
            nowCnt++;
            int changeIndex=blueS.top();
            blueS.pop();
            input[changeIndex]='R';
        }
        else blueS.pop();
    }
    if(result>nowCnt) result=nowCnt;
    //cout<<nowCnt<<"\n";

    cout<<result;
    return 0;
}