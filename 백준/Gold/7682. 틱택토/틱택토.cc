#include <iostream>
#include <vector>
using namespace std;

bool judge(string s){
    int xCnt=0, oCnt=0;
    bool xWin=false, oWin=false;
    for(int i=0;i<9;i++){
        if(s[i]=='X') xCnt++;
        else if(s[i]=='O') oCnt++;
    }
    for(int i=0;i<3;i++){ //행 조사
        int xx=0, oo=0;
        for(int j=0;j<3;j++){
            if(s[i*3+j]=='X') xx++;
            else if(s[i*3+j]=='O') oo++;
        }
        if(xx==3) xWin=true;
        if(oo==3) oWin=true;
    }
    for(int i=0;i<3;i++){ //열 조사
        int xx=0, oo=0;
        for(int j=0;j<3;j++){
            if(s[j*3+i]=='X') xx++;
            else if(s[j*3+i]=='O') oo++;
        }
        if(xx==3) xWin=true;
        if(oo==3) oWin=true;
    }
    int xx=0, oo=0;
    for(int i=0;i<3;i++){  //동남방향 대각     
        if(s[i*4]=='X') xx++;
        else if(s[i*4]=='O') oo++;
    }
    if(xx==3) xWin=true;
    if(oo==3) oWin=true;

    xx=0, oo=0;
    for(int i=1;i<=3;i++){  //서남방향 대각     
        if(s[i*2]=='X') xx++;
        else if(s[i*2]=='O') oo++;
    }
    if(xx==3) xWin=true;
    if(oo==3) oWin=true;
    if(!(xCnt==oCnt||xCnt-1==oCnt)) return false;
    if(xCnt>5||oCnt>4) return false;
    if(xWin){
        if(oWin||!(xCnt-1==oCnt)) return false;
    }
    if(oWin&&!(xCnt==oCnt)) return false;
    if(!(xWin||oWin)&&(xCnt+oCnt)<9) return false;
    return true;
}

int main(){
    vector<string> result;
    while(1){
        string s; cin>>s;
        if(s=="end") break;
        if(judge(s)) result.push_back("valid");
        else result.push_back("invalid");
    }
    for(int i=0;i<result.size();i++) cout<<result[i]<<"\n";


    return 0;
}