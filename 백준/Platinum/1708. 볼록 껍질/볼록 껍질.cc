#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

struct pos {
    long long x,y;
};

vector <pos> v;
stack <pos> s;

long long ccw(pos a, pos b, pos c) { //CCW 알고리즘
    return a.x * b.y + b.x * c.y + c.x * a.y - (b.x * a.y + c.x * b.y + a.x * c.y);
}

bool compare(pos a, pos b){ //반시계 정렬
    
    long long cc = ccw(v[0], a, b);
    
    if (cc) //각도가 작은 순
        return cc>0;
    else if (a.y != b.y) //y가 작은 순
        return a.y < b.y;
    else //x가 작은 순
        return a.x < b.x;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t;
    cin>>t;
    
    v.resize(t);
    for (int i=0; i<t; i++){
        cin>>v[i].x>>v[i].y;
    }
    
    for (int i=1; i<t; i++){ //1부터
        if(v[i].y < v[0].y || (v[i].y == v[0].y && v[i].x < v[0].x)){
            
            long long temp = v[0].x;
            v[0].x = v[i].x;
            v[i].x = temp;
            
            temp = v[0].y;
            v[0].y = v[i].y;
            v[i].y = temp;
        }
    }
    
    sort(v.begin()+1, v.end(), compare);
    
    s.push(v[0]);
    s.push(v[1]);
    
    for(int i=2; i<t; i++){
        while (s.size() >= 2){
            pos top2 = s.top();
            s.pop();
            
            pos top1 = s.top();
            if (ccw(top1, top2, v[i]) > 0){
                s.push(top2); //다시 push
                break;
            }
        }
        s.push(v[i]);
    }
    
    cout<<s.size();
    
    return 0;
}