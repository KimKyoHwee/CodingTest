#include <bits/stdc++.h>
using namespace std;

int N, bus;
vector<vector<int> > want_T(1001);  // 원래 행렬의 전치행렬 SCC용 
int want[1001];  //want[i]는 i번째 사람이 원하는 사람. 
bool visited[1001];
int timeF[1001]; //인덱스별 finish time 
int fin_time=0;  //finish time
queue<int> time_q;  //finish time 작은  순서대로 pop되는 스택  
int ccs[1001];  //각 인덱스별로 자기가 몇번째 컴포넌트에 포함되어 있는지 저장.  
int com_cnt=1; //몇번째 컴포넌트인지 세기
vector<pair<int, int> > component;  //만들어진 컴포넌트들의 최소값과 최댓값 저장 
int result;
int dp[1001][1001];

void dfs(int index){        //입력받은 노드의 component 돌면서 finish time만 배열에 저장해준다. 
	visited[index]=1;
	fin_time++;
	if(visited[want[index]]==0){
		dfs(want[index]);
	}
	fin_time++;
	timeF[index]=fin_time;
	time_q.push(index);
}

void dfs_second(int index){  
	vector<int> imsi;  //임시로 컴포넌트들 인덱스 모아놓기 
	int c_size=1; //현재까지 자기를 포함한 컴포넌트 크기  
	imsi.push_back(index);
	while(1){
		visited[index]=1;
		if(visited[want[index]]==0){
			c_size++;
			index=want[index];
			imsi.push_back(index);
			continue;
		}
		else if(ccs[want[index]]==0) break;  //자기 포함한 컴포넌트 완성 
		else if(ccs[want[index]]!=0){  //다른 컴포넌트에 자기가 낄 수 있을 때  그 컴포넌트의 최댓값 늘려주고 return 
			component[ccs[want[index]]].second+=c_size;
			ccs[index]=ccs[want[index]]; //자기 또한 그 컴포넌트에 포함됐음을 저장  
			return;
		}
	}
	//여기는 자기를 포함한 컴포넌트가 새로 만들어졌을때만 실행되어야함
	for(int i=0;i<imsi.size();i++){  //새로 만들어지는 컴포넌트의 구성원들의 컴포넌트 번호 배열에 저장. 
		ccs[imsi[i]]=com_cnt;
	}
	component.push_back({c_size, c_size});  //새로 만들어진 컴포넌트 번호에 맞추어 크기 저장. 
	com_cnt++;
	return;
}

void knap_dfs(int weight, int level) {  //최종 컴포넌트 길이들 조합하며 결과값을 뽑아내는 dfs 
	if(level>component.size()) return;
	if(result<weight) result=weight;
	if(weight+component[level].first>bus) return knap_dfs(weight, level+1);
	for(int j=component[level].first;j<=component[level].second;j++){
		if((weight+j)<=bus) knap_dfs(weight+j, level+1); 
	}
	return knap_dfs(weight, level+1);
}


int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	component.push_back({-1, -1}); //0번 인덱스 쓰레기값  
	cin>>N>>bus;
	for(int i=1;i<=N;i++){
		int imsi; cin>>imsi;
		want[i]=imsi;
		want_T[imsi].push_back(i);      //want[imsi]는 imsi번 사람을 원하는 사람들의 인덱스 벡터  
	}
	//모든 노드들에 finish time작성. 
	for(int i=1;i<=N;i++){
		if(visited[i]==0) dfs(i);
	}
	fill(visited,&visited[1001], 0);
	
	while(!time_q.empty()){
		if(visited[time_q.front()]==0)dfs_second(time_q.front());
		time_q.pop();
	}
	
	//knap_dfs(0,1);
	//cout<<result;
	

	for(int i=1;i<component.size();i++){
		for(int j=component[i].first;j<=component[i].second;j++){
			for(int k=1;k<=bus;k++){
				if(j<=k) dp[k][i]=max(dp[k][i-1], dp[k-j][i-1]+j);
				else dp[k][i]=max(dp[k][i],dp[k][i-1]);
				result=max(result, dp[k][i]);
			}
		}
	}
	cout<<result;
	
	
	return 0;
}