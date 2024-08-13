#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int operate(char op, int lastSum, int nowNum) {
    if(op == '+') return lastSum + nowNum;
    else return lastSum - nowNum;
}

void dfs(string expression, int currentNum, int endN, vector<string> &results) {
    if (currentNum == endN) {
        int sum = 0;
        char lastOp = '+';
        int nowNum = 0;
        for (int i = 0; i < expression.size(); ++i) {
            if (expression[i] == '+' || expression[i] == '-') {
                sum = operate(lastOp, sum, nowNum);
                lastOp = expression[i];
                nowNum = 0;
            } else if (expression[i] != ' ') {
                nowNum = nowNum * 10 + (expression[i] - '0');
            }
        }
        sum = operate(lastOp, sum, nowNum);  // 마지막 숫자 처리

        if (sum == 0) {
            results.push_back(expression);
        }
        return;
    }

    dfs(expression + "+" + to_string(currentNum + 1), currentNum + 1, endN, results);
    dfs(expression + "-" + to_string(currentNum + 1), currentNum + 1, endN, results);
    dfs(expression + " " + to_string(currentNum + 1), currentNum + 1, endN, results);
}

int main() {
    int N;
    cin >> N;
    vector<vector<string>> all_results;

    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        vector<string> results;
        dfs("1", 1, n, results);  // 1부터 시작
        all_results.push_back(results);
    }
    for(int i=0;i<N;i++){
        sort(all_results[i].begin(), all_results[i].end());
    }
    for (const auto& results : all_results) {
        for (const auto& expr : results) {
            cout << expr << "\n";
        }
        cout << "\n";  // 각 테스트 케이스 사이에 빈 줄 출력
    }

    return 0;
}
