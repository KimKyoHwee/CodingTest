#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int N,L,R, moveY[4]={-1,1,0,0}, moveX[4]={0,0,-1,1};
vector<vector<int>> board;

bool check(int a, int b){
    int sum=a-b;
    if(sum<0) sum*=(-1);
    if(sum>=L&&sum<=R) return true;
    else return false;
}

int dfs(unordered_map<int, int> &people, vector<vector<bool>> &visited, int index, int y, int x, int cnt){
    visited[y][x]=true;
    cnt++;
    for(int i=0;i<4;i++){
        int nextY=y+moveY[i];
        int nextX=x+moveX[i];
        if(nextY<0||nextX<0||nextY>=N||nextX>=N||visited[nextY][nextX]) continue;
        if(check(board[nextY][nextX], board[y][x])) cnt+=dfs(people, visited, index, nextY, nextX, 0);
    }
    people[index]+=board[y][x];
    board[y][x]=index;
    return cnt;
}

bool dayStart(){
    //cout<<"dfs\n";
    vector<vector<bool>> visited(N,vector<bool>(N, false));
    unordered_map<int, int> people; //각 인덱스별 인구
    int index=1;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(visited[i][j]) continue;
            int nodeCnt=dfs(people, visited, index, i, j, 0);
            people[index]/=nodeCnt;
            index++;
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++) board[i][j]=people[board[i][j]];
    }
   //cout<<"index : "<<index<<"\n";
    if(index==(N*N+1)) return false;
    return true;
}

int main(){
    cin>>N>>L>>R;
    board.resize(N,vector<int>(N));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++) cin>>board[i][j];
    }
    int result=0;
    while(1){
        /*
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<"\n";
        }
        */
        if(dayStart()) result++;
        else break;
    }
    cout<<result;
    return 0;
}