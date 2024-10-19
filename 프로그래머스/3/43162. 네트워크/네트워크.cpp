#include <string>
#include <vector>
#include <iostream>
using namespace std;
void dfs(int node, vector<bool>& visited, vector<vector<int>> computers, int& cnt){
    cnt++;
    visited[node]=true;
    for(int i=0;i<computers[node-1].size();i++){  //i+1번째 노드로 갈 수 있는가
        if(computers[node-1][i]==1){
            if(!visited[i+1]) dfs(i+1, visited, computers, cnt); 
        }
    }
    return;
}
int solution(int n, vector<vector<int>> computers) {
    vector<bool> visited(n+1, false);
    int answer = 0;
    for(int i=1;i<=n;i++){ //node순회
        if(visited[i]) continue;
        int cnt=0;
        dfs(i, visited, computers, cnt);
        //if(cnt>1) answer++;
        answer++;
    }
    return answer;
}