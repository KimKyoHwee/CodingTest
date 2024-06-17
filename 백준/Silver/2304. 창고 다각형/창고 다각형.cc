#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int result=0;
vector<pair<int, int>> vp;
int N;
int main(){
    int maxHeight=0;
    int maxIndex=0;
    cin>>N;
    for(int i=0;i<N;i++){
        int a,b;
        cin>>a>>b;
        if(b>maxHeight) {
            maxHeight=b;
            maxIndex=a;
        }
        vp.push_back({a,b});
    }
    sort(vp.begin(), vp.end());
    int past=vp[0].first;
    int nowHeight=vp[0].second;
    for(int i=0;i<vp.size();i++){
        int now=vp[i].first;
        if(now==maxIndex){
            result+=((now-past)*nowHeight);
            break;
        }
        if(vp[i].second>nowHeight){
            result+=((now-past)*nowHeight);
            nowHeight=vp[i].second;
            past=now;
        }
    }
    past=vp[N-1].first;
    nowHeight=vp[N-1].second;
    for(int i=N-1;i>=0;i--){
        int now=vp[i].first;
        if(now==maxIndex){
            result+=((past-now)*nowHeight);
            break;
        }
        if(vp[i].second>nowHeight){
            result+=((past-now)*nowHeight);
            nowHeight=vp[i].second;
            past=now;
        }
    }
    result+=maxHeight;
    cout<<result;
    return 0;
}