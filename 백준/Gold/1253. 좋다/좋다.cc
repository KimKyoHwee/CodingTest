#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> inputs;
map<int, bool> dict;
int main(){
    int answer=0;
    cin>>N;
    for(int i=0;i<N;i++){
        int n; cin>>n;
        inputs.push_back(n);
    }
    sort(inputs.begin(), inputs.end());
    for(int i=0;i<N;i++){
        int target=inputs[i];
        int left=0, right=N-1, sum=0;
        bool flag=false;
        while(left<right){
            sum=inputs[left]+inputs[right];
            if(sum<target){
                left++;
                continue;
            }
            else if(sum>target){
                right--;
                continue;
            }
            else{
                if(left==i) left++;
                else if(right==i) right--;
                else{
                    flag=true;
                    break;
                }
            }
        }
        if(flag) answer++;
    }
    cout<<answer;
    return 0;
}