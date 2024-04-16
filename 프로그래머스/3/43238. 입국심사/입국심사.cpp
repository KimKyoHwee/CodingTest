
// #include <string>
// #include <vector>
// #include <iostream>
// #include <algorithm>
// using namespace std;
// int timesLen=0;
// bool canFinishInTime(vector<int> times, long long time, int n){
//     int canFinish=0;
//     for(int i=0;i<timesLen;i++){
//         canFinish+=(time/times[i]);
//     }
//     return canFinish>=n;
// }
// long long parametric(long long left, long long right, int n, vector<int> times){
//     /*
//     if(left==right) return left;
//     long long mid = left + (right - left) / 2;
//     if(canFinishInTime(times, mid, n)){
//         return parametric(left, mid, n, times);
//     }
//     else return parametric(mid+1, right, n, times);
//     */
//     while (left < right) {
//         long long mid = left + (right - left) / 2;
//         cout<<mid<<"값: "<<mid<<"\n"; 
//         if (canFinishInTime(times, mid, n)) {
//             cout<<"mid값 통과\n";
//             right = mid;
//         } else {
//             cout<<"mid값 불통과\n";
//             left = mid + 1;
//         }
//     }
//     return left;
// }

// long long solution(int n, vector<int> times) {
//     /*
//     long long left, right;
//     timesLen=times.size();
//     int minTime=2000000000, maxTime=0;
//     for(int i=0;i<timesLen;i++){
//         if(minTime>times[i]) minTime=times[i];
//         if(maxTime<times[i]) maxTime=times[i];
//     }
//     left=(long long)(n/timesLen*minTime);
//     if(n%timesLen==0){  //딱 나누어떨어져서 올림계산 필요 없으면 
//         right=(long long)(n/timesLen)*maxTime;
//     } 
//     else right=(long long)((n/timesLen)+1)*maxTime;    
//     long long answer = parametric(left, right, n, times);
//     return answer;
//     */
//     sort(times.begin(), times.end());  // 심사 시간을 오름차순으로 정렬
//     long long left = times[0];
//     long long right = (long long)times.back() * n;
//     cout<<left<<", "<<right<<"\n";
//     return parametric(left, right, n, times);
    
// }
#include <vector>
#include <algorithm>

using namespace std;

bool canFinishInTime(const vector<int>& times, long long time, int n) {
    long long canFinish = 0;
    for (int t : times) {
        canFinish += time / t;
        if (canFinish >= n) return true; // 더 이상 계산할 필요 없이 바로 반환
    }
    return false; // canFinish가 n에 도달하지 못했다면 false 반환
}

long long parametricSearch(long long left, long long right, int n, const vector<int>& times) {
    while (left < right) {
        long long mid = left + (right - left) / 2;
        if (canFinishInTime(times, mid, n)) {
            right = mid; // 가능하다면 더 작은 시간을 탐색
        } else {
            left = mid + 1; // 불가능하다면 시간을 늘려야 함
        }
    }
    return left; // 최소 시간 반환
}

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());
    long long left = times[0];
    long long right = (long long)times.back() * (n / times.size() + 1); // 더 현실적인 right 값 설정
    return parametricSearch(left, right, n, times);
}
