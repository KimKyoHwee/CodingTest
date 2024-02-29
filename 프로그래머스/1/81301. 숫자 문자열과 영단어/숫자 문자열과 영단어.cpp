#include <string>
#include <vector>
using namespace std;

//전역변수
vector<string> stringToInteger={"zero", "one", "two", "three", "four", "five",
                           "six", "seven", "eight", "nine"};
int digit=0;  //자릿수
string partOfString="";  //숫자에 대응되는 영단어 저장하는 임시 string
//


bool paramCanBeInteger(string param){
    bool flag=false;
    for(int i=0;i<stringToInteger.size();i++){
        if(stringToInteger[i]==param) flag=true;
    }
    return flag;
}

int toInteger(string s){
    for(int i=0;i<stringToInteger.size();i++){
        if(s==stringToInteger[i]) return i;
    }
}

int solution(string s) {
    int answer = 0;
    for(auto c:s){
        if(isdigit(c)) answer=answer*10+c-'0';
        else{
            partOfString+=c;
            if(paramCanBeInteger(partOfString)){
                answer=answer*10+toInteger(partOfString);
                partOfString="";
            }
        }
        digit++;
    }
    
    
    return answer;
}