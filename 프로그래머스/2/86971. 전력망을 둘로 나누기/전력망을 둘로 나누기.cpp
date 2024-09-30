#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
void dfs(int node, vector<bool>& visited, map<int, vector<int>> edges, set<int>& indexes){
    indexes.insert(node);
    visited[node]=true;
    for(int i=0;i<edges[node].size();i++){
        int nextNode=edges[node][i];
        if(visited[nextNode]) continue;
        dfs(nextNode, visited, edges, indexes);
    }
}
int judge(int n, vector<vector<int>> wires){
    int result=987654321;
    vector<bool> visited(n+1, false);
    vector<int> results;
    map<int, vector<int>> edges;
    for(int i=0;i<wires.size();i++){
        int first=wires[i][0];
        int second=wires[i][1];
        edges[first].push_back(second);
        edges[second].push_back(first);
    }
    for(int i=1;i<=n;i++){
        if(visited[i]) continue;
        set<int> indexes;
        dfs(i, visited, edges, indexes);
        results.push_back(indexes.size());
    }
    return abs(results[0]-results[1]);
}
int solution(int n, vector<vector<int>> wires) {
    int answer = 987654321;
    for(int i=0;i<wires.size();i++){
        vector<vector<int>> copy(wires);
        copy.erase(copy.begin()+i);
        int nowAnswer=judge(n, copy);
        answer=min(answer, nowAnswer);
    }
    return answer;
}