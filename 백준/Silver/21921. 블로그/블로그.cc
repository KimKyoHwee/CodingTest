#include <iostream>
#include <vector>
using namespace std;
vector<int> sum; //누적합
int N,X;

int main(){
    cin>>N>>X;
    sum.push_back(0);  //[0]번째 비우기
    for(int i=1;i<=N;i++){
        int n; cin>>n;
        sum.push_back(n+sum[i-1]);  //누적합
    }
    int maxVisit=0;
    int result=0; //기간이 몇개인지
    for(int i=X;i<=N;i++){
        int nowSum=sum[i]-sum[i-X];
        if(maxVisit==nowSum) result++;
        else if(maxVisit<nowSum){
            maxVisit=nowSum;
            result=1;
        }
    }
    if(maxVisit==0){
        cout<<"SAD";
        return 0;
    }
    cout<<maxVisit<<"\n"<<result;
    return 0;
}