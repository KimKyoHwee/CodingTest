#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool dfs(string s1, string s2){
    if(s1.length()==s2.length()) return s1==s2;
    if(s2.back()=='A'){
        string imsi=s2;
        imsi.pop_back();
        if(dfs(s1, imsi)) return true;
    }
    if(s2.front()=='B'){
        string imsi=s2;
        imsi.erase(imsi.begin());
        reverse(imsi.begin(), imsi.end());
        if(dfs(s1, imsi)) return true;
    }
    return false;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    
    if (dfs(s1, s2)) cout << 1;
    else cout << 0;
    return 0;
}
