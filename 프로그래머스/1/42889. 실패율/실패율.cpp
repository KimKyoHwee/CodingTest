#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<double, int> &a, pair<double, int> &b) {
    // 실패율이 같은 스테이지라면, 작은 번호의 스테이지를 기준으로 오름차순 정렬
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double, int>> failure;
    int noClearStage;
    int noReachStage = 0; // 모두 1 스테이지는 도달함
    
    for (int i=1; i<=N; i++) {
        int noClearStage = count(stages.begin(), stages.end(), i);
        
        // 스테이지에 도달한 유저가 없는 경우
        if (stages.size() == noReachStage) {
            failure.push_back({0, i});
            continue;
        }
        
        failure.push_back({(double)noClearStage / (double)(stages.size() - noReachStage), i});
        noReachStage += noClearStage;
    }
    
    sort(failure.begin(), failure.end(), cmp);
    
    for (int i=0; i<failure.size(); i++) {
        answer.push_back(failure[i].second);
    }
    
    return answer;
}