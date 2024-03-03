#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string new_id) {
    //1단계
    for (int i = 0; i < new_id.size(); i++) {
        if (isupper(new_id[i])) new_id[i] = tolower(new_id[i]);
    }
    //2단계
    for (int i = 0; i < new_id.size(); i++) {
        if (!isalnum(new_id[i]) && new_id[i] != '-' && new_id[i] != '_' && new_id[i] != '.') {
            new_id.erase(new_id.begin() + i--);
        }
    }
    //3단계
    for (int i = 0; i < new_id.size()-1; i++) {
        if (new_id[i] == '.' && new_id[i + 1] == '.') {
            new_id.erase(new_id.begin() + i);
            i--;
        }
    }
    //4단계
    if (new_id[0] == '.') new_id.erase(new_id.begin());
    if (new_id[new_id.size() - 1] == '.') new_id.erase(new_id.end() - 1);
    //5단계
    if (new_id == "") new_id.push_back('a');
    //6단계
    if (new_id.size() >= 16) {
        new_id = new_id.substr(0, 15);
        if (new_id[14] == '.') new_id.erase(14);
    }
    //7단계
    if (new_id.size() <= 2) {
        while (new_id.size() != 3) {
            new_id.push_back(new_id[new_id.size() - 1]);
        }
    }
    return new_id;
}