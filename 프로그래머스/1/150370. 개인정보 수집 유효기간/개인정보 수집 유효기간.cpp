#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>

using namespace std;

//전역변수
map<string, int> tMap; //terms에 해당하는 map
vector<string> pV; //privacies를 저장하는 벡터

struct Date{
    int year;
    int month;
    int day;
};

Date changeDate(int year, int month, int day, int term){ //날짜 계산기
    Date rDate;
    month=month+term;  day-=1;
    if(day<1){
        day=28;
        month-=1;
    }
    
    if(month>12){
        while(month>12){
            year+=1;
            month-=12;
        }
    }
    rDate.year=year;
    rDate.month=month;
    rDate.day=day;
    return rDate;
}

bool destroyOrNot(Date today, Date compare){ //현재와 비교할 날짜 입력받고 파기안해도 되면 true리턴
    if(today.year<compare.year) return false;
    else if(today.year==compare.year){
        if(today.month<compare.month) return false;
        else if(today.month==compare.month){
            if(today.day<=compare.day) return false;
        }
    }
    /*
    cout<<"today : "<<today.year<<", "<<today.month<<", "<<today.day<<"\n";
    cout<<"compare : "<<compare.year<<", "<<compare.month<<", "<<compare.day<<"\n";
    */
    return true;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    //terms벡터 맵으로 매핑하기
    for(int i=0;i<terms.size();i++){
        string type; int month;
        stringstream ss(terms[i]);
        ss>>type>>month;
        tMap[type]=month;
    }
    //today 매핑
    Date todayDate;
    for(int i=0;i<today.size();i++) if(today[i]=='.') today[i]=' '; //sstream 쓰기 쉽게하려고
    stringstream todaySs(today);
    todaySs>>todayDate.year>>todayDate.month>>todayDate.day;
    //privacles 벡터 돌리면서 한개씩 today와 비교하기
    for(int i=0;i<privacies.size();i++){
        int year, month, day; string termType; //privacies전용 파싱
        string str=privacies[i];
        for(int i=0;i<str.size();i++) if(str[i]=='.') str[i]=' ';
        stringstream strSs(str);
        strSs>>year>>month>>day>>termType;
        Date compareDate=changeDate(year, month, day, tMap[termType]);
        if(destroyOrNot(todayDate, compareDate)) answer.push_back(i+1);
    }
    return answer;
}