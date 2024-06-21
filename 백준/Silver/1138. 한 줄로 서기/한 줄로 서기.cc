#include <iostream>
#include <vector>
using namespace std;
int N;

int main(){
    cin>>N;
    vector<int> line(N+1);
    vector<int> input(N+1);
    for(int i=1;i<=N;i++){
        int n; cin>>n;
        input[i]=n;
    }
    for(int i=N;i>=1;i--){
        line.insert(line.begin()+input[i]+1, i);
    }
    for(int i=1;i<=N;i++) cout<<line[i]<<" ";
}