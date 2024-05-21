#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int zeroCnt, oneCnt;
int main(){
    string s; cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0') zeroCnt++;
        else oneCnt++;
    }
    zeroCnt/=2;
    oneCnt/=2;
    vector<int> answerIndexV;
    for(int i=s.size()-1;i>=0;i--){
        if(!oneCnt) break;
        if(s[i]=='1'){
            answerIndexV.push_back(i);
            oneCnt--;
        }
    }
    for(int i=0;i<s.size();i++){
        if(!zeroCnt) break;
        if(s[i]=='0'){
            answerIndexV.push_back(i);
            zeroCnt--;
        }
    }
    sort(answerIndexV.begin(), answerIndexV.end());
    for(int i=0;i<answerIndexV.size();i++) cout<<s[answerIndexV[i]];
    return 0;
}