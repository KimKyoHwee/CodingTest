#include <iostream>
#include <string>

using namespace std;
int answer=0;
void calculate(string input, char oper){
    int nowInput=stoi(input);
    if(oper=='+') answer+=nowInput;
    else answer-=nowInput;
}
int main(){
    string input; cin>>input;
    string nowInput="";
    bool flag=false;
    for(int i=0;i<input.size();i++){
        if(input[i]>='0'&&input[i]<='9') nowInput+=input[i];
        else{
            char oper=input[i];
            if(!flag){ //-들어온적 없으면 무조건 더하기
                answer+=stoi(nowInput);
                if(oper=='-') flag=true;
            }
            else answer-=stoi(nowInput);
            nowInput="";
        }
    }
    if(flag) answer-=stoi(nowInput);
    else answer+=stoi(nowInput);
    cout<<answer;
}