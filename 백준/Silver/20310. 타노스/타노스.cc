#include <iostream>

using namespace std;
int zeroCnt, oneCnt;
int main(){
    string s; cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0') zeroCnt++;
        else oneCnt++;
    }
    string answer="";
    for(int i=0;i<(zeroCnt/2);i++) answer+='0';
    for(int i=0;i<(oneCnt/2);i++) answer+='1';
    cout<<answer;

    return 0;
}