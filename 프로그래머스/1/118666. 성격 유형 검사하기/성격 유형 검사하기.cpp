#include <string>
#include <vector>
#include <map>
using namespace std;
//전역변수
map<char, int> point;  //각 성향별 점수
//전역변수 종료

char choice(char c1, char c2){  //각 성향중 한개씩 결정
    if(point[c1]>point[c2]) return c1;
    else if(point[c2]>point[c1]) return c2;
    else{  //두개가 점수 같을 시 사전순으로
        if (c1<c2) return c1;
        else return c2;
    }
}


string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    for(int i=0;i<survey.size();i++){  //모든 survey돌면서 각 성향별 점수 측정
        //각 survey별 성향 분리
        char c1 = survey[i][0];
        char c2 = survey[i][1];
        //survey별 choice에 따른 점수 계산
        switch(choices[i]){
            case 1:
                point[c1]+=3;
                break;
            case 2:
                point[c1]+=2;
                break;
            case 3:
                point[c1]+=1;
                break;
            case 4:
                break;
            case 5:
                point[c2]+=1;
                break;
            case 6:
                point[c2]+=2;
                break;
            case 7:
                point[c2]+=3;
                break;
        }
    }
    //각 성향별 결정
    answer+=choice('R','T');
    answer+=choice('C','F');
    answer+=choice('J','M');
    answer+=choice('A','N');
    /*
    answer=answer.concat(choice('R','T'));
    answer=answer.concat(choice('C','F'));
    answer=answer.concat(choice('J','M'));
    answer=answer.concat(choice('A','N'));
    */
    return answer;
}