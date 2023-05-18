#include <bits/stdc++.h>
using namespace std;

int N,M;
int MIN=0;
int MAX=0;
int iA[301];
vector<int> iV;

bool pandan(int mid){
	int cnt=1;
	int sum=0;
	for(int i=1;i<=N;i++){
		if(sum+iA[i]<=mid) sum+=iA[i];
		else {
			if(iA[i]>mid) return false;
			sum=iA[i];
			cnt++;
		}
	}
	return cnt<=M;
	
}

int parametric(int min, int max){
	if(min>=max) return max;
	int mid=(min+max)/2;
	if(pandan(mid)) return parametric(min,mid);
	else return parametric(mid+1,max);
	
}
int main(){
	cin>>N>>M;
	//입력받기 + max와 min 처리 
	for(int i=1;i<=N;i++){
		int imsi;
		cin>>imsi;
		iA[i]=imsi;
		MAX+=imsi;
		if(MIN<imsi) MIN=imsi;
	}
	//max~0까지 이분탐색 
	int result=parametric(MIN,MAX);
	cout<<result<<"\n";
	int imsiSum=0;  //구한 최소의 그룹 최댓값으로 구슬 갯수 출력 
	int imsiCount=0;
	for(int i=1;i<=N;i++){
		
		if(imsiSum+iA[i]<=result){
			imsiSum+=iA[i];
			imsiCount++;
		}
		else{
			iV.push_back(imsiCount);
			imsiSum=iA[i];
			imsiCount=1;
		}
	
	} 
	iV.push_back(imsiCount);
	while (iV.size() < M) {
		for (int i = 0; i < iV.size(); i++) {
			if (iV[i] > 1) {
				iV.insert(iV.begin() + i + 1, iV[i] / 2);
				iV[i] = iV[i] - iV[i] / 2;
				break;
			}
		}
	}
	for(int i=0;i<iV.size();i++){
		cout<<iV[i]<<" ";
	}
	
	return 0;
}