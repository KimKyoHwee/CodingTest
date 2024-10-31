#include <iostream>
#include <vector>
using namespace std;

int K, N;
vector<int> input;

bool judge(long long mid) {
    long long cnt = 0;
    for (int i = 0; i < K; i++) {
        long long num = input[i];
        cnt += (num / mid);
    }
    return cnt >= N;
}

long long parametric(long long left, long long right) {
    if (left == right) return right;
    long long mid = (left + right + 1) / 2;
    if (judge(mid)) return parametric(mid, right);
    else return parametric(left, mid - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int mini = 2147483647, maxi = 0;
    cin >> K >> N;

    for (int i = 0; i < K; i++) {
        int num;
        cin >> num;
        mini = min(mini, num);
        maxi = max(maxi, num);
        input.push_back(num);
    }

    long long answer = parametric(1, maxi);
    cout << answer;
    return 0;
}
