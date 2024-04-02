#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
using namespace std;
double graph[101][101];
vector<pair<double, double>> pV;
int N;
double dist[101];
int nearest[101];
double result = 0;
double calculateDistance(pair<double, double> a, pair<double, double> b) {
	double sum = pow((b.first - a.first), 2) + pow((b.second - a.second), 2);
	return sqrt(sum);
}

int main() {
	cin >> N;
	fill(graph[0], &graph[N][N + 1], 9999);
	for (int i = 0; i < N; i++) {
		double x, y;
		cin >> x >> y;
		pV.push_back({ x,y });
	}
	for (int i = 0; i < pV.size(); i++) {
		for (int j = 0; j < pV.size(); j++) {
			if (i == j) continue;
			double distance = calculateDistance(pV[i], pV[j]);
			graph[i][j] = distance;
			graph[j][i] = distance;
		}
	}
	//프림 알고리즘 시작 0번째 별부터 N-1번째 별까지 찍어야됨
	for (int i = 1; i <= N - 1; i++) {
		dist[i] = graph[0][i];  //dist초기화
		nearest[i] = 0;  //시작노드로 nearest 다 초기화
	}
	//초기화 종료
	for (int i = 0; i < (N - 1); i++) { //N-1개의 별 추가
		double min = 10000;
		int vnear = 0; //이번 턴에 추가할 별 인덱스
		for (int j = 1; j <= N - 1; j++) {  //1번 별부터 N-1번 별까지 돌기
			if (dist[j] == -1) continue;
			if (min > dist[j]) {
				min = dist[j];
				vnear = j;  //이번에 뽑을 별 구하기
			}
		}
		//cout << i+1 << "번째 추가한 별 : " << pV[vnear].first << ", " << pV[vnear].second << "\n";
		result += min; //별 거리의 총합
		dist[vnear] = -1;
		for (int j = 1; j <= N - 1; j++) {  //이번에 뽑은 별로 인해서 거리 가까워지는 별 있는지 체크
			if (dist[j] > graph[vnear][j]) {
				dist[j] = graph[vnear][j];
				nearest[j] = vnear;
			}
		}
	}
	printf("%.2lf", result);
	return 0;
}