#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;
int N,K,L;
int moveY[4]={0,1,0,-1}, moveX[4]={1,0,-1,0}; //동남서북
int main(){
    cin>>N>>K;
    vector<vector<int>> board(N+1, vector<int>(N+1, 0));
    vector<pair<int, char>> changes;
    set<pair<int, int>> body;
    queue<pair<int, int>> tail;
    for(int i=0;i<K;i++){
        int y,x;
        cin>>y>>x;
        board[y][x]=1; //사과
    }
    cin>>L;
    for(int i=0;i<L;i++){
        int num;
        char c;
        cin>>num>>c;
        changes.push_back({num+1, c});
    }
    int turn=0, nowY=1, nowX=1, changesIndex=0, moveIndex=0;
    body.insert({1,1});
    tail.push({1,1});
    while(1){
        turn++; 
        if(changesIndex!=-1&&turn==changes[changesIndex].first){
            if(changes[changesIndex].second=='D'){
                moveIndex++;
                if(moveIndex>3) moveIndex=0;
            }
            else{
                moveIndex--;
                if(moveIndex<0) moveIndex=3;
            }
            changesIndex++;
            if(changesIndex>=L) changesIndex=-1;
        }
        int nextY=nowY+moveY[moveIndex];
        int nextX=nowX+moveX[moveIndex];
        if(nextY<1||nextY>N||nextX<1||nextX>N) break;
        if(body.find({nextY, nextX})!=body.end()) break;
        body.insert({nextY, nextX});
        tail.push({nextY, nextX});
        if(board[nextY][nextX]==1){
            board[nextY][nextX]=0;
        }
        else{
            pair<int,int> delTail=tail.front();
            tail.pop();
            body.erase(delTail);
        }
        nowY=nextY;
        nowX=nextX;
    }
    cout<<turn;
    return 0;
}