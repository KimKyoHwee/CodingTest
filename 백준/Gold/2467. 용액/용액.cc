#include <iostream>
#include <vector>
using namespace std;
int N, nowLeft, nowRight, minSum=2100000000, leftResult, rightResult;


bool cmp(int nowSum){
    if(minSum<0) minSum*=(-1);
    if(nowSum<0) nowSum*=(-1);
    return nowSum<minSum;
}
int main(){
    cin>>N;
    vector<int> input(N);
    for(int i=0;i<N;i++) cin>>input[i];
    nowLeft=0; nowRight=N-1;
    while(1){
        if(nowLeft==nowRight) break;
        int nowSum=input[nowLeft]+input[nowRight];
        if(nowSum==0){
            cout<<input[nowLeft]<<" "<<input[nowRight];
            return 0;
        }
        if(cmp(nowSum)){
            minSum=nowSum;
            leftResult=nowLeft;
            rightResult=nowRight;
        }
        if(nowSum>0) nowRight--;
        else nowLeft++;
    }
    cout<<input[leftResult]<<" "<<input[rightResult];
    return 0;
}