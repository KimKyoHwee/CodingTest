#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool judge(int mid, vector<int> citations){
    int cnt=0;
    for(int i=0;i<citations.size();i++){
        if(citations[i]>=mid) cnt++;
        else break;
    }
    if(cnt>=mid) return true;
    else return false;
}
int parametric(int left, int right, vector<int> citations){
    if(left==right) return right;
    int mid=(left+right+1)/2;
    if(judge(mid, citations)) return parametric(mid, right, citations);
    else return parametric(left, mid-1, citations);
}
int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), greater<int>());
    int maxNum=citations[0];
    return parametric(0,maxNum, citations);
}