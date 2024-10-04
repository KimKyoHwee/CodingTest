#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int N,K,S;
int main() {
    cin >> N >> K;

    // board 초기화: 1은 i->j 경로가 있음, -1은 j->i 경로가 있음, 0은 경로 없음
    vector<vector<int>> board(N + 1, vector<int>(N + 1, 0));

    // 간선 정보 입력
    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        board[a][b] = 1;   // a가 b보다 먼저 발생
        board[b][a] = -1;  // b가 a보다 나중에 발생
    }

    // 플로이드-와샬 알고리즘: 경유지를 거쳐 갈 수 있는 경로 업데이트
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (board[i][k] == 1 && board[k][j] == 1) {
                    board[i][j] = 1;   // i -> k -> j 경로가 있으면 i -> j 경로도 있음
                    board[j][i] = -1;  // j -> i 경로는 반대 방향
                }
            }
        }
    }
    cin>>S;
    vector<int> result;
    for(int i=0;i<S;i++){
        int a,b;
        cin>>a>>b;
        if(a==b) {
            result.push_back(0);
            continue;
        }
        if(board[a][b]==1) result.push_back(-1);
        else if(board[a][b]==-1) result.push_back(1);
        else result.push_back(0);
    }
    for(int i=0;i<result.size();i++) cout<<result[i]<<"\n";
}