#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int N,M, moveY[4]={-1,1,0,0}, moveX[4]={0,0,-1,1}; //상하좌우
struct Point{
    int y,x;
    bool operator<(const Point& other) const {
        if (y != other.y)
            return y > other.y;
        return x > other.x;
    }
};
Point makeP(int y,int x){
    Point point;
    point.y=y;
    point.x=x;
    return point;
}
int main(){
    cin>>M>>N;
    vector<vector<int>> board(N+1, vector<int>(M+1,-1));
    for(int i=1;i<=N;i++){
        string s; cin>>s;
        s=" "+s;
        for(int j=1;j<=M;j++) {
            board[i][j]=(int)s[j]-'0';
        }
    }
    priority_queue<pair<int, Point>, vector<pair<int, Point>>, greater<pair<int, Point>>> pq; //벽부순갯수, 좌표
    vector<vector<bool>> visited(N+1, vector<bool>(M+1, false));
    pq.push({0, makeP(1,1)});
    visited[1][1]=true;
    while(!pq.empty()){
        int nowWeight=pq.top().first;
        Point nowPoint=pq.top().second;
        if(nowPoint.y==N&&nowPoint.x==M){
            cout<<nowWeight;
            break;
        }
        //visited[nowPoint.y][nowPoint.x]=true;
        pq.pop();
        for(int i=0;i<4;i++){
            int nextY=nowPoint.y+moveY[i];
            int nextX=nowPoint.x+moveX[i];
            if(nextY<1||nextY>N||nextX<1||nextX>M||visited[nextY][nextX]) continue;
            visited[nextY][nextX]=true;
            if(board[nextY][nextX]==1) pq.push({nowWeight+1, makeP(nextY,nextX)});
            else pq.push({nowWeight, makeP(nextY,nextX)});
        }
    }

    return 0;
}