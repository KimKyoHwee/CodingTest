#include <string>
#include <vector>

using namespace std;

//전역변수
int countOfZero=0; //0이 몇개인지
int countOfCorrect=0; //일치하는 숫자 갯수
//전역변수 종료
int getRank(int counts){
    switch(counts){
        case 6: 
            return 1;
        case 5:
            return 2;
        case 4:
            return 3;
        case 3:
            return 4;
        case 2:
            return 5;
        default:
            return 6;
    }
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    for(int i=0;i<lottos.size();i++){
        if(lottos[i]==0) {
            countOfZero++;
            continue;
        }
        for(int j=0;j<win_nums.size();j++){
            if(lottos[i]==win_nums[j]){
                countOfCorrect++;
                break;
            }
        }
    }
    int highCorrect=countOfCorrect+countOfZero;
    if(highCorrect>6) highCorrect=6;
    int highRank=getRank(highCorrect);
    int lowRank=getRank(countOfCorrect);
    answer.push_back(highRank);
    answer.push_back(lowRank);
    return answer;
}