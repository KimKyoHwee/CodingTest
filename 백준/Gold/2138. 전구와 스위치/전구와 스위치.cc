#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, cnt1=1, cnt2=0;
void turnOn(vector<int>& arr, int index){
    for(int i=index-1;i<=index+1;i++){
        if(i<0||i>=N) continue;
        if(arr[i]==0) arr[i]=1;
        else arr[i]=0;
    }
}
int main(){
    cin>>N;
    vector<int> arr1(N), arr2(N), arr3(N);
    string s1,s2; cin>>s1>>s2;
    for(int i=0;i<N;i++) {
        arr1[i]=s1[i]-'0';
        arr2[i]=arr1[i];
    }
    for(int i=0;i<N;i++) arr3[i]=s2[i]-'0';
    turnOn(arr1, 0);
    for(int i=1;i<N;i++){
        if(arr1[i-1]!=arr3[i-1]){
            turnOn(arr1, i);
            cnt1++;
        }
        if(arr2[i-1]!=arr3[i-1]){
            turnOn(arr2, i);
            cnt2++;
        }
    }
    if(arr1!=arr3) cnt1=987654321;
    if(arr2!=arr3) cnt2=987654321;
    int result=min(cnt1, cnt2);
    if(result>=900000000) result=-1;
    cout<<result;
}