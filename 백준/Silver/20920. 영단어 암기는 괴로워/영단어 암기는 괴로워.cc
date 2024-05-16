#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int N,M;
map<string, int> wordCnt;
struct WordInfo{
    string word;
    int cnt;
};
vector<WordInfo> wordV;

bool cmp(WordInfo a, WordInfo b){
    if(a.cnt!=b.cnt) return a.cnt>b.cnt;
    else if(a.word.length()!=b.word.length()) return a.word.length()>b.word.length();
    else return a.word<b.word;
}

int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        string s; cin>>s;
        if(s.length()<M) continue;
        wordCnt[s]++;
    }

    for(auto it:wordCnt){
        WordInfo wordInfo;
        wordInfo.word=it.first;
        wordInfo.cnt=it.second;
        wordV.push_back(wordInfo);
    }
   
    sort(wordV.begin(), wordV.end(), cmp);
    for(int i=0;i<wordV.size();i++){
        cout<<wordV[i].word<<"\n";
    }

    return 0;
}