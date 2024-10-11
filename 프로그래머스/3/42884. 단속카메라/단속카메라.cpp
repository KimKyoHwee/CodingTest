#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
    // 차량 경로를 진출 시점을 기준으로 오름차순 정렬
    sort(routes.begin(), routes.end(), [](vector<int> a, vector<int> b) {
        return a[1] < b[1];
    });

    int answer = 0;
    int camera_position = -30001;  // 카메라가 아직 설치되지 않았다고 가정
    
    for (int i = 0; i < routes.size(); i++) {
        int nowA = routes[i][0];
        int nowB = routes[i][1];

        // 현재 카메라가 이 차량의 경로에 포함되지 않는다면 새로운 카메라 설치
        if (camera_position < nowA) {
            answer++;
            camera_position = nowB;  // 새로운 카메라는 이 차량이 나가는 지점에 설치
        }
    }

    return answer;
}
