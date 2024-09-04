#include <iostream>
#include <string>
#include <vector>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    int len = number.size() - k; // 만들어야 할 숫자의 길이
    for (char num : number) {
        // 스택에 있는 마지막 숫자가 현재 숫자보다 작으면 제거
        while (!answer.empty() && answer.back() < num && k > 0) {
            answer.pop_back();
            k--;
        }
        answer.push_back(num);
    }
    
    // 만약 k가 남아 있다면 뒤에서부터 제거
    answer.resize(len);
    return answer;
}

