#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <vector>
#include <tuple>
#include <map>
using namespace std;

//변수선언
map<string, int> give; //준 선물의 수
map<string, int> take; //받은 선물의 수
map<string, int> priority; //선물 지수(우선순위 결정)
map<pair<string, string>, int> counts; // a가 b에게 준 선물의 수
map<string, int> presents;  //최종적으로 받는 선물 수

void addCounts(string s1, string s2){
    if(counts.find({s1, s2})!=counts.end()){
        counts[{s1, s2}]++;
        return;
    }
    else{
        counts.insert({{s1,s2},1});
    }
}

int getCounts(string s1, string s2){
    if(counts.find({s1, s2})!=counts.end())
        return counts[{s1, s2}];
    else return 0;
}

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    //선물기록 1개씩 돌며 파싱 후 값처리
    for(int i=0;i<gifts.size();i++){  
        string str1, str2;
        stringstream ss(gifts[i]);
        ss>>str1>>str2;
        addCounts(str1, str2); //2명의 친구가 주고받은 선물 수 갱신
        give[str1]++; //준사람 갯수 추가
        take[str2]++; //받은사람 갯수 추가
    }
    //선물 지수 계산
    for(int i=0;i<friends.size();i++) {  
        priority[friends[i]]=give[friends[i]]-take[friends[i]];
    }
    
    //각 친구들 비교하며 최종적으로 받을 선물 수 정리
    for(int i=0;i<friends.size();i++){
        for(int j=i+1;j<friends.size();j++){
            if(friends[i]==friends[j]) continue; //같은 친구 이름 나오면 continue
            //두명씩 돌며 선물 더 많이 준 사람에게 다음턴 선물 1개 추가
            if( getCounts(friends[i], friends[j])>getCounts(friends[j], friends[i]))
                presents[friends[i]]++;
            else if(getCounts(friends[i], friends[j])<getCounts(friends[j], friends[i]))
                presents[friends[j]]++;
            //두명이 서로 준 선물 갯수가 같을 경우 priority 계산
            else if(getCounts(friends[i], friends[j])==getCounts(friends[j], friends[i])){
                if(priority[friends[i]]>priority[friends[j]]) presents[friends[i]]++;
                else if(priority[friends[i]]<priority[friends[j]]) presents[friends[j]]++;
            }
        }
    }
    //최종적으로 다음턴에 받을 선물 수가 정산되었으니, 최댓값 계산
    for(int i=0;i<friends.size();i++) 
        if(answer<presents[friends[i]]) answer=presents[friends[i]];
    return answer;
}




