#include <iostream>
#include <vector>

using namespace std;
int N;
vector<vector<int>> board;
vector<int> nowIndex;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    for(int i=0;i<N;i++){
        vector<int> inputV;
        for(int j=0;j<N;j++){
            int num; cin>>num;
            inputV.push_back(num);
        }
        board.push_back(inputV);
        nowIndex.push_back(N-1);
    }
    for(int j=0;j<N;j++){
        int maxIndex=0;
        int maxInt=-1111111111;
        for(int i=0;i<N;i++){
            int nowInt=board[nowIndex[i]][i];
            if(nowInt>maxInt){
                maxInt=nowInt;
                maxIndex=i;
            }
        }
        nowIndex[maxIndex]--;
        if(j==(N-1)) cout<<maxInt;
    }
    return 0;
}