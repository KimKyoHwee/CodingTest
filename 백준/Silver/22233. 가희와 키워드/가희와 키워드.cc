#include <iostream>
#include <unordered_set>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>
using namespace std;
int N,M;
vector<int> result;
unordered_set<string> words;
int main(){
    ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);
    cin>>N>>M;
    for(int i=0;i<N;i++){
        string s; cin>>s;
        words.insert(s);
    }
    for(int i=0;i<M;i++){
        string s; cin>>s;
        stringstream ss(s);
        vector<string> sV;
        string token;
        while(getline(ss, token, ',')){
            sV.push_back(token);
        }
        for(int j=0;j<sV.size();j++){
            string s2=sV[j];
            if(words.find(s2)!=words.end()){
                N--;
                words.erase(s2);
            }
        }
        result.push_back(N);
    }
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<"\n";
    }
    return 0;
}