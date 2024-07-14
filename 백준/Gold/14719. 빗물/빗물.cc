#include <iostream>
#include <vector>
using namespace std;
int H,W, highest, nowH, result;  //가장 높은곳, 현재까지 가장 높은 높이

int main(){
    cin>>H>>W;
    vector<int> input(W), high(W);  //입력값, 현재까지 가장 높은곳
    for(int i=0;i<W;i++) {
        cin>>input[i];
        if(nowH<input[i]) {  //가장 높은 곳 찾기 + 왼->오 기준 현재까지 가장 높은 높이 저장(high배열)
            nowH=input[i];
            highest=i;
        }
        high[i]=nowH;
    }
    nowH=0;
    for(int i=(W-1);i>=highest;i--){  // 오->왼 방향 처리
        if(nowH<input[i]) nowH=input[i];
        high[i]=nowH;
    }
    for(int i=0;i<W;i++) result+=(high[i]-input[i]);
    cout<<result;
}