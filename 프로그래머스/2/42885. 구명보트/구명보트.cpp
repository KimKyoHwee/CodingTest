#include <vector>
#include <algorithm>

int solution(std::vector<int> people, int limit) {
    std::sort(people.begin(), people.end()); // 사람들의 몸무게를 정렬
    int answer = 0; // 그룹 수 초기화
    int left = 0; // 가장 가벼운 사람 인덱스
    int right = people.size() - 1; // 가장 무거운 사람 인덱스

    while (left <= right) {
        if (people[left] + people[right] <= limit) {
            // 가장 가벼운 사람과 가장 무거운 사람을 함께 그룹으로 묶을 수 있는 경우
            left++; // 가벼운 사람을 그룹에서 제거
        }
        // 무거운 사람은 반드시 그룹에 포함
        right--; // 무거운 사람을 그룹에서 제거
        answer++; // 그룹 수 증가
    }
    
    return answer; // 그룹 수 반환
}
