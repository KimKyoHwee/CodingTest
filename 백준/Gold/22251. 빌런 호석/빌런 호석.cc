#include <iostream>

using namespace std;
bool led[10][7]={{1,1,1,0,1,1,1}, {0,0,1,0,0,1,0}, {1,0,1,1,1,0,1}, {1,0,1,1,0,1,1}, {0,1,1,1,0,1,0}, {1,1,0,1,0,1,1}, {1,1,0,1,1,1,1}, {1,0,1,0,0,1,0}, {1,1,1,1,1,1,1}, {1,1,1,1,0,1,1}};
int N,K,P,X; 

int compare(int n1, int n2){
    int cnt=0;
    for(int i=0;i<7;i++){
        if(led[n1][i]!=led[n2][i]) cnt++;
    }
    return cnt;
}
bool canChange(int num){
    if(num==X) return false;
    int cnt=0;
    int nowX=X;
    for(int i=0;i<K;i++){
        int a=num%10;
        int b=nowX%10;
        num/=10;
        nowX/=10;
        if(a==b) continue;
        cnt+=compare(a,b);
    } 
    return cnt<=P;
}

int main(){
    cin>>N>>K>>P>>X;
    int result=0;
    for(int i=1;i<=N;i++){
        if(canChange(i)) result++;
    }
    cout<<result;
    return 0;
}