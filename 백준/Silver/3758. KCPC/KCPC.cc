#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct Team {
    int node;
    int sum;
    int tryCnt;
    int lastTime;
    map<int, int> solved;
    Team() : node(0), sum(0), tryCnt(0), lastTime(0) {}  // 초기화 리스트 사용
};

bool cmp(Team a, Team b) {
    if (a.sum != b.sum) return a.sum > b.sum;
    else if (a.tryCnt != b.tryCnt) return a.tryCnt < b.tryCnt;
    else return a.lastTime < b.lastTime;
}

int main() {
    int TT;
    cin >> TT;
    vector<int> result;

    while (TT--) {
        int N, K, t, M;
        cin >> N >> K >> t >> M;

        vector<Team> teamV(N + 1);  // 팀의 인덱스를 1부터 사용하기 위해 N+1 크기로 생성

        for (int i = 1; i <= N; i++) {
            teamV[i].node = i;
        }

        int quizNum = 1;
        while (M--) {  // 한 테스트케이스의 문제정보들 처리하기
            int i, j, k;
            cin >> i >> j >> k;

            teamV[i].tryCnt++;  // 문제풀이 횟수 추가
            teamV[i].lastTime = quizNum;  // 마지막 제출 시간 업데이트

            if (teamV[i].solved[j] < k) {
                teamV[i].solved[j] = k;  // 기존보다 높은 점수면 점수 바꾸기
            }

            quizNum++;
        }

        for (int i = 1; i <= N; i++) {  // 각 팀별 점수 총합 정리
            teamV[i].sum = 0;
            for (auto iter = teamV[i].solved.begin(); iter != teamV[i].solved.end(); iter++) {
                teamV[i].sum += iter->second;
            }
        }

        sort(teamV.begin() + 1, teamV.end(), cmp);  // 팀 정렬 (1부터 시작)

        int rank = 1;
        for (int i = 1; i <= N; i++) {
            if (teamV[i].node == t) {
                result.push_back(rank);
                break;
            }
            rank++;
        }
    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << "\n";
    }

    return 0;
}
