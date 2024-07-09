#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int N,d,k,c;
int result=0;
int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    cin>>N>>d>>k>>c;
    vector<int> iV(N);
    for(int i=0;i<N;i++) cin>>iV[i];
    
    //슬라이딩 윈도우 시작
    unordered_map<int, int> um;
    for(int i=0;i<k;i++) {
        if(i>=N) break;
        um[iV[i]]++;
    }
    if(um[c]==0);
    result=um.size();
    int umSize=um.size();
    for(int i=k;i<N+k-1;i++){  //슬라이딩
        int index=i;
        if(index>=N) index-=N;
        um[iV[i-k]]--;  //뺼거빼고
        if(um[iV[i-k]]==0) {
            um.erase(iV[i-k]);
        }
        um[iV[index]]++;  //더할거 더하고
        umSize=um.size();
        if(um[c]==0);
        if(result<um.size()) result=um.size();
    }
    cout<<result;

    return 0;
}