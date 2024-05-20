#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

struct Team{
    int node;
    int sum;
    int tryCnt;
    int lastTime;
    map<int, int> solved;
};
bool cmp(Team a, Team b){
    if(a.sum!=b.sum) return a.sum>b.sum;
    else if(a.tryCnt!=b.tryCnt) return a.tryCnt<b.tryCnt;
    else return a.lastTime<b.lastTime;
}
int TT;
int main(){
    vector<int> result;
    cin>>TT;
    while(TT--){
        vector<Team> teamV;
        int N,K,t,M;
        cin>>N>>K>>t>>M;
        int quizNum=1; 
        while(M--){  //한 테스트케이스의 문제정보들 처리하기
            int i,j,k;
            cin>>i>>j>>k;
            bool flag=true;
            for(int l=0;l<teamV.size();l++){  //이미 팀벡터에 들어있다면 그곳에 추가, 없다면 팀벡터에 추가
                if(teamV[l].node==i){
                    flag=false;
                    teamV[l].tryCnt++;  //문제풀이 횟수 추가
                    teamV[l].lastTime=quizNum;  //마지막에 푼 문제 번호
                    //if(teamV[i].solved[j]<k) teamV[i].solved[j]=k;  //기존보다 높은 점수면 점수바꾸기
                    if(teamV[l].solved[j]<k) teamV[l].solved[j]=k;
                    break;
                }
            }
            if(flag){  //만약 팀벡터에 팀이 존재하지 않는다면
                Team team;
                team.solved[j]=k;
                team.tryCnt=1;
                team.node=i;
                team.lastTime=quizNum;
                teamV.push_back(team);
            }
            quizNum++;
        }
        for(int l=0;l<teamV.size();l++){  //각 팀별 점수 총합 정리
            for(auto iter=teamV[l].solved.begin();iter!=teamV[l].solved.end();iter++){
                teamV[l].sum+=iter->second;
                //cout<<teamV[l].node<<"번참가자 "<<iter->second<<"점 추가해서 "<<teamV[l].sum<<"\n";
            }
        }
        sort(teamV.begin(), teamV.end(), cmp);
        /*
        for(int ii=0;ii<teamV.size();ii++){
            cout<<teamV[ii].node<<": "<<teamV[ii].tryCnt<<", "<<teamV[ii].lastTime<<" ";
        }
        cout<<"\n";
        */
        int rank=0;
        for(int l=0;l<teamV.size();l++){
            if(teamV[l].node==t) break;
            else rank++;
        }
        result.push_back(rank+1);
    }
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<"\n";
    }
    return 0;
}