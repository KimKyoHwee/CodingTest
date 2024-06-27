#include <iostream>
#include <vector>
#include <map>
using namespace std;

int start = 0, endP = 0, result = 1;
map<int, int> iM;
int N, K;

int main() {
    cin >> N >> K;
    vector<int> iV(N);
    for (int i = 0; i < N; i++) {
        cin >> iV[i];
    }
    
    iM[iV[0]]++;
    while (endP < N - 1) {
        endP++;
        iM[iV[endP]]++;
        while (iM[iV[endP]] > K) {
            iM[iV[start]]--;
            start++;
        }
        int len = endP - start + 1;
        if (len > result) result = len;
    }
    
    cout << result;
    return 0;
}
