#include <iostream>
#include <vector>
using namespace std;
vector<int> iV;
vector<string> sV;
vector<string> result;
int N,M;

bool check(int index, int num){
    if(iV[index]>=num) return true;
    else return false;
}
int parametric(int left, int right, int num){
    if(left==right) return left;
    int mid=(left+right)/2;
    if(check(mid, num)) return parametric(left, mid, num);
    else return parametric(mid+1, right, num);
}
int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        string s;
        int n;
        cin>>s>>n;
        sV.push_back(s);
        iV.push_back(n);
    }
    for(int i=0;i<M;i++){
        int num;
        cin>>num;
        int resultIndex=parametric(0,N-1,num);
        result.push_back(sV[resultIndex]);
    }
    for(int i=0;i<result.size();i++) cout<<result[i]<<"\n";
    return 0;
}