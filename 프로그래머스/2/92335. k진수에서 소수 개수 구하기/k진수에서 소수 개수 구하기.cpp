#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

long long changeNum(int n, int k){  //n을 k진수로 변경
    long long answer=0;
    long long cnt=1; //자릿수(long long필수!)
    while(n>0){
        answer+=((n%k)*cnt);
        n/=k;
        cnt*=10; //자릿수 추가
    }
    return answer;
}

bool isSosu(long long n){  //소수판별
    if(n<2) return false;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    return true;
}

int solution(int n, int k) {
    long long kNum=changeNum(n, k);
    int answer = 0;
    long long imsi=0;  //뭉텅이 숫자 임시 저장 
    long long cnt=1; //자릿수
    while(kNum>0){
        if(kNum%10==0){
            kNum/=10;
            if(imsi!=0){  //지금까지 뽑아둔 뭉텅이 숫자가 있으면
                if(isSosu(imsi)) answer++; //뽑아둔 뭉텅이숫자 소수검정
                imsi=0;
                cnt=1;
            } 
        }
        else{
            imsi+=((kNum%10)*cnt);
            cnt*=10;
            kNum/=10;
        }
    }
    if(imsi!=0){
        if(isSosu(imsi)) answer++;
    }
    
    return answer;
}