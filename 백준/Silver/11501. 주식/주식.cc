#include <iostream>
#include <vector>
using namespace std;
int T, N;
vector<long long> answer;
int main(){
    cin>>T;
    while(T--){
        int price[1000001];
        int sellPrice[1000001];
        cin>>N;
        for(int i=1;i<=N;i++){
            cin>>price[i];
        }
        int maxSellPrice=0;
        for(int i=N;i>=1;i--){
            sellPrice[i]=maxSellPrice;
            if(price[i]>maxSellPrice) maxSellPrice=price[i];
        }
        long long sum=0;
        for(int i=1;i<=N;i++){
            if(price[i]<sellPrice[i]) sum+=(sellPrice[i]-price[i]);
        }
        answer.push_back(sum);
    }
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<"\n";
    }
    return 0;
}