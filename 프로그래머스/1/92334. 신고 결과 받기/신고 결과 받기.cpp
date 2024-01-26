#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <iostream>
using namespace std;

//전역변수
map<string, vector<string>> reportList; //'key'가 신고한 유저 목록
map<string, int> reportCnt; //'key'가 신고당한 횟수
vector<string> suspended;  //정지당한 유저 목록
//전역변수 종료
bool findUser(string user, vector<string> sV){  //user가 sV에 존재하는지
    if(find(sV.begin(), sV.end(),user)==sV.end()) return false;
    else return true;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    //신고 목록 순회하며 reportList, reportCnt 채우기
    for(int i=0;i<report.size();i++){
        string s1, s2;
        stringstream ss(report[i]);
        ss>>s1>>s2;
        if(!findUser(s2, reportList[s1])){
            reportList[s1].push_back(s2); //s1이 s2를 신고함
            reportCnt[s2]++;  //s2가 신고를 1회 당함
        }
    }
    //신고 목록 처리가 끝났으니, 각 유저들중 신고 2회 이상 당한 유저 찾기
    for(int i=0;i<id_list.size();i++){
        if(reportCnt[id_list[i]] >= k) suspended.push_back(id_list[i]);
    }
    //각 유저 돌면서 정지당한 유저를 신고한 횟수 정리
    for(int i=0;i<id_list.size();i++){
        string user=id_list[i];  //유저
        for(int j=0;j<reportList[user].size();j++){
            string reported=reportList[user][j];  //유저가 신고한 유저
            if(findUser(reported, suspended)) answer[i]++;
        }
    }
    for(int i=0;i<id_list.size();i++){
        cout<<reportCnt[id_list[i]]<<"\n";
    }
    for(int i=0;i<suspended.size();i++){
        cout<<suspended[i]<<"\n";
    }
    return answer;
}