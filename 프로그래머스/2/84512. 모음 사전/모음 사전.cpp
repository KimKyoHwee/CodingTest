#include <string>
#include <vector>
#include <map>
using namespace std;
map<string, int> dict;
char words[5]={'A','E','I','O','U'};
int ranks=1;
void dfs(string nowWord){
    if(nowWord.size()>=6) return;
    dict[nowWord]=ranks;
    ranks++;
    for(int i=0;i<5;i++){
        dfs(nowWord+words[i]);
    }
}
int solution(string word) {
    for(int i=0;i<5;i++) dfs(string(1,words[i]));
    return dict[word];
}