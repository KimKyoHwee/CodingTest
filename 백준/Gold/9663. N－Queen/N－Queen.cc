#include <iostream>
#include <vector>
using namespace std;
int N, result=0;
int board[15];
int abs(int num) {
    if(num<0) return (num*(-1));
    else return num;
}
bool promise(int depth){
    int nowNum=board[depth];
    for(int i=0;i<depth;i++){
        if(nowNum==board[i]||(depth-i)==abs(nowNum-board[i])) return false;
    }
    return true;
}

void dfs(int depth){

    for(int i=1;i<=N;i++){
        board[depth]=i;
        if(promise(depth)){
            if(depth==(N-1)){
                result++;
                return;
            }
            dfs(depth+1);
        }
    }
}

int main(){
    cin>>N;
    dfs(0);
    cout<<result;
    return 0;
}