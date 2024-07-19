#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,C, maxInput, minInput=2100000000, near[200001];
vector<int> input;
/*
bool pandan(int mid){
    int start=minInput;
    for(int i=0;i<(C-1);i++) {
        if((start+mid)>maxInput) return false;
        start=near[start+mid];
        if(start==-1) return false;
    }
    return true;    
}
*/
bool pandan(int mid){  //집의 위치 정렬한 후 최근에 와이파이 설치한 곳부터 현재 순회중인 집의 위치까지의 거리가 mid이상이면 와이파이 설치하는식으로 판단
    int start=input[0];
    int cnt=1;  //제일 앞의 집에 와이파이 설치 -> 기본 1개로 시작
    for(int i=1;i<N;i++){
        if((input[i]-start)>=mid){
            cnt++;
            start=input[i];
        }
    }
    if(cnt>=C) return true;
    else return false;
}

int parametric(int left, int right){
    if(left==right) return left;
    int mid=(left+right+1)/2;
    if(pandan(mid)) return parametric(mid, right);
    else return parametric(left, mid-1);
}

int main(){
    cin>>N>>C;
    for(int i=0;i<N;i++){  //입력값 처리
        int n; cin>>n;
        if(n>maxInput) maxInput=n;  
        if(n<minInput) minInput=n;
        input.push_back(n);
    }
    sort(input.begin(), input.end());
    /*
    //여기부터 near벡터에 가장 가까우면서 더 멀리있는 집의 위치를 저장
    fill(near, &near[200001], -1);
    int lastH=0;
    for(int i=0;i<N;i++){
        int n=input[i];
        for(int j=lastH;j<=n;j++) near[j]=n;
        lastH=n+1;
    }
    */
    cout<<parametric(1, maxInput);
}