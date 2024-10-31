#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<char> cs;
    int result=0;
    string s; cin>>s;
    for(int i=0;i<s.size();i++){
        char c=s[i];
        if(c=='('&&s[i+1]==')'){ //레이저
            result+=cs.size();
            i++;
            continue;
        }
        if(c=='(') cs.push(c);
        else {
            result++; //막대기 기본적으로 1개 카운트
            cs.pop();
        }
    }
    cout<<result;

}