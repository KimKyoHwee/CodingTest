#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N,M;
vector<pair<int, int>> ladder, snake;
struct Point{
    int nowPoint,turn;
};
struct cmp{
    bool operator()(Point a, Point b){
        return a.turn>b.turn;
    }
};
Point makePoint(int point, int turn){
    Point p;
    p.nowPoint=point;
    p.turn=turn;
    return p;
}
int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        int a,b; cin>>a>>b;
        ladder.push_back({a,b});
    }
    for(int i=0;i<M;i++){
        int a,b; cin>>a>>b;
        snake.push_back({a,b});
    }
    int start=1;
    priority_queue<Point, vector<Point>, cmp> pq;
    pq.push(makePoint(start,0));
    vector<bool> visited(101, false);
    visited[start]=true;
    while(!pq.empty()){
        Point nowP=pq.top();
        pq.pop();
        int nowPoint=nowP.nowPoint;
        int nowTurn=nowP.turn;
        if(nowPoint==100){
            cout<<nowTurn;
            break; 
        }
        for(int i=1;i<=6;i++){
            int nextPoint=nowPoint+i;
            if(nextPoint>100) continue;
            for(int j=0;j<ladder.size();j++){
                if(ladder[j].first==nextPoint){
                    nextPoint=ladder[j].second;
                    break;
                }
            }
            for(int j=0;j<snake.size();j++){
                if(snake[j].first==nextPoint){
                    nextPoint=snake[j].second;
                    break;
                }
            }
            if(visited[nextPoint]) continue;
            visited[nextPoint]=true;
            pq.push(makePoint(nextPoint, nowTurn+1));
        }
    }
}