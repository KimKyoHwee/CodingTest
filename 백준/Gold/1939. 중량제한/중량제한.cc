#include <bits/stdc++.h>
using namespace std;

int N,M;
//vector<pair<int , int> > pArr[100001];  //pArr[a].{b,c}는 a와b 사이의 다리 가중치가 c  
int root[100001]; // Kruskal용 부모 노드 가리키기. 
int resultA, resultB;  //결과를 찾아야하는 A와 B노드 

typedef struct node{   // Kruskal 사용하기 위하여 edge들의 내림차순 정렬 위해 구조체 선언 
	int a, b, c;
}Node;
vector<Node> nodeV;            //구조체 벡터(Kruskal용) 

bool compare(Node x, Node y){  //Kruskal edge내림차순 정렬용 비교함수  
	return x.c>y.c;
}

void create_set(int n){  //union-set
	for(int i=1;i<=n;i++) root[i]=i;
}
pair<int, int> find_set(int n){  // union-set (union함수에서 높이 필요하므로 {루트노드, 높이} 반환 
	int height=1;
	while(1){
		int imsi=root[n];
		if(imsi==n) return {n, height};
		else {
			n=imsi;
			height++;
		}
	}
}
void union_set(int x, int y){  //union_set
	pair<int, int> imsiA=find_set(x); 
	pair<int, int> imsiB=find_set(y);
	if(imsiA.second>=imsiB.second) root[imsiA.first]=imsiB.first;
	else root[imsiB.first]=imsiA.first;
}


int main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	cin>>N>>M;
	for(int i=0;i<M;i++){
		int A,B,C;
		cin>>A>>B>>C;
		//pArr[A].push_back({B,C});
		Node imsi;
		imsi.a=A;
		imsi.b=B;
		imsi.c=C;
		nodeV.push_back(imsi);
	}
	cin>>resultA>>resultB;
	//기본입력 끝
	sort(nodeV.begin(),nodeV.end(), compare);  //Kruskal용 
	//union-set시작 
	create_set(N);
	int nodeVcnt=0;
	while(1){
		int imsiA=nodeV[nodeVcnt].a;
		int imsiB=nodeV[nodeVcnt].b;
		union_set(imsiA, imsiB);
		if(find_set(resultA).first==find_set(resultB).first){
			cout<<nodeV[nodeVcnt].c;
			return 0;
		}
		nodeVcnt++;
	}
	return 0;
}