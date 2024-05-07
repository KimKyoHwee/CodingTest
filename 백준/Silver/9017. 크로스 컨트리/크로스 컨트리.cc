#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
using namespace std;
int T, N;
vector<int> result;

bool cmp(pair<int, vector<int>> a, pair<int, vector<int>> b) {
	int aSum = 0, bSum=0;
	for (int i = 0; i < 4; i++) {
		aSum += a.second[i];
		bSum += b.second[i];
	}
	if(aSum!=bSum) return aSum < bSum;
	else {
		if (a.second[4] == b.second[4]) return a.second[5] < b.second[5];
		else return a.second[4] < b.second[4];
	}
}
int main() {
	cin >> T;
	while (T--) {

		vector<int> rank;  //등수표
		map<int, int> teamCnt;  //각 팀별 인원수
		vector<int> eraseTeam;  //지워야하는 팀 숫자 목록
		vector<pair<int, vector<int>>> finalRank;
		cin >> N;
		for (int i = 0; i < N; i++) {
			int team; cin >> team;
			teamCnt[team]++;
			rank.push_back(team);
		}
		for (auto iter = teamCnt.begin(); iter != teamCnt.end(); iter++) {
			if ((iter->second) != 6) eraseTeam.push_back(iter->first);
			else if ((iter->second) == 6) finalRank.push_back({ iter->first, {} });
		}
		for (int i = 0; i < eraseTeam.size(); i++) {
			int eraseNum = eraseTeam[i];
			auto newEnd = remove(rank.begin(), rank.end(), eraseNum);
			rank.erase(newEnd, rank.end());
		}
		if (finalRank.size() == 1) {
			result.push_back(finalRank[0].first);
			continue;
		}
		for (int i = 0; i < finalRank.size(); i++) {  // 미리 6명인 팀숫자들 finalRank에 넣어두고, 해당 팀숫자의 점수들 vector형식으로 입력
			int nowTeam = finalRank[i].first;
			for (int j = 0; j < rank.size(); j++) {
				if (rank[j] == nowTeam) finalRank[i].second.push_back(j);
			}
		}
		sort(finalRank.begin(), finalRank.end(), cmp);
		result.push_back(finalRank[0].first);
	}
	for (int i = 0; i < result.size(); i++) cout << result[i] << "\n";
	return 0;
}