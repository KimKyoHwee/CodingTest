#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;
int N, M; //집의 개수, 길의 개수
unordered_map<int, int> head;  //집의 번호들이 1부터 순차적 증가할거란 보장이 없음, 즉 집이 100개있다고 집 번호가 101번이 없다는 보장이 없음

struct Edge{
    int a,b,weight;
};
struct cmp{
    bool operator()(Edge first, Edge second){
        return first.weight>second.weight;
    }
};
int findHead(int node){
    if(node==head[node]) return node;
    return findHead(head[node]);
}
Edge makeE(int a,int b,int weight){
    Edge edge;
    edge.a=a;
    edge.b=b;
    edge.weight=weight;
    return edge;
}
bool checkHead(Edge edge){  //합칠수 있으면 true반환
    if(findHead(edge.a)==findHead(edge.b)) return false;
    else return true;
}
void mergeNode(Edge edge){
    int aHead=findHead(edge.a);
    int bHead=findHead(edge.b);
    if(aHead<bHead) head[bHead]=aHead;
    else head[aHead]=bHead;
}
int main(){
    cin>>N>>M;
    priority_queue<Edge, vector<Edge>, cmp> pq;

    for(int i=0;i<M;i++){
        int a,b,c;
        cin>>a>>b>>c;
        head[a]=a;
        head[b]=b;
        Edge edge=makeE(a,b,c);
        pq.push(edge);
    }
    int edgeCnt=0; //N-1개 연결되면 끝
    int result=0;
    while(!pq.empty()){
        Edge nowEdge=pq.top();
        pq.pop();
        if(checkHead(nowEdge)) {
            mergeNode(nowEdge);
            edgeCnt++;
            if(edgeCnt==N-1){
                cout<<result;
                return 0;            
            }
            result+=nowEdge.weight;
        }
    }
    return 0;
}