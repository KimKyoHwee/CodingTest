#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main(){
    vector<int> answer;
    priority_queue<int, vector<int>, greater<int>> pQ;
    int N, x;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>x;
        if(x==0){
            if(pQ.empty()) {
                answer.push_back(0);
                continue;
            }
            else{
                answer.push_back(pQ.top());
                pQ.pop();
                continue;
            }
        }
        pQ.push(x);
    }
    for(int i=0;i<answer.size();i++) cout<<answer[i]<<"\n";
    return 0;
}