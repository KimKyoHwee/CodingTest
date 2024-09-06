#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
int result;
struct Word{
    string word;
    int temp, index;  //몇번바꿧는지, 몇번째 word인지
};
struct Compare{
    bool operator()(const Word& a, const Word& b){
        return a.temp>b.temp;
    }
};
bool ifChange(string before, string after){
    if(before.size()!=after.size()) return false;
    int notSame=0;
    for(int i=0;i<before.size();i++){
        char a=before[i];
        char b=after[i];
        if(a!=b) notSame++;
    }
    if(notSame==1) return true;
    return false;
}

int bfs(string begin, string target, vector<string> words){
    Word before;
    before.word=begin; before.temp=0; before.index=0;
    vector<bool> visited(words.size(), false);
    priority_queue<Word, vector<Word>, Compare> pq;
    pq.push(before);
    while(!pq.empty()){
        Word now=pq.top();
        pq.pop();
        if(now.word==target) return now.temp;
        for(int i=0;i<words.size();i++){
            if(visited[i]) continue;
            if(ifChange(now.word, words[i])){
                visited[i]=true;
                Word next;
                next.word=words[i];
                next.temp=now.temp+1;
                next.index=i;
                pq.push(next);
            }
        }
    }
    return 0;
    
}

int solution(string begin, string target, vector<string> words) {
    int answer = bfs(begin, target, words);
    return answer;
}