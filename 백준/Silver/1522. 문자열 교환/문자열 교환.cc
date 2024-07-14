#include <iostream>
#include <vector>
using namespace std;
int N, aCnt, pA, pB;  //포인터A, 포인터B
int result, nowA; //결과값과 구간 내 a갯수
int main(){
    string input;
    cin>>input;
    N=input.size();
    
    for(int i=0;i<N;i++){
        if(input[i]=='a') aCnt++;
    }
    pB=aCnt-1;
    for(int i=pA;i<=pB;i++){
        if(input[i]=='a') nowA++;
    }
    result=aCnt-nowA;
    for(int i=1;i<N;i++){
        //앞포인터가 a면 a 1개 빼고, 뒷포인터보다 한칸 뒤가 a면 a 1개 더하기
        if(input[pA]=='a') nowA--;
        if(input[(pB+1)%N]=='a') nowA++;
        pA++;
        pB++;
        if(result>(aCnt-nowA)) result=(aCnt-nowA);
    }
    cout<<result;
    
}