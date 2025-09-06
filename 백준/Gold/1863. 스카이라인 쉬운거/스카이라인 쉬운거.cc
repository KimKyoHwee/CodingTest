#include <iostream>
#include <stack>
/**
왼쪽부터 가면서 마지막보다 높아지면 건물+1, 낮아지거나 같아지면 기존꺼 위에서부터 빼기 (기존 건물들 최대한 다 마감치기)
*/
using namespace std;
int N, cnt=0;
int main(){
    stack<int> s; s.push(0);
    cin>>N;
    for(int i=0;i<N;i++){
        int x,y; 
        cin>>x>>y;
        while(!s.empty()){
            int now=s.top();
            if(now>y) s.pop();
            else if (now==y) break;
            else{
                cnt++;
                break;
            }
        }
        s.push(y);
    }
    cout<<cnt;
    return 0;
}

