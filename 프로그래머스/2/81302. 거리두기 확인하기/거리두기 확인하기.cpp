#include <string>
#include <vector>
//전역변수
int moveY[8]={-2,-1,0,1,2,1,0,-1};  //시계방향
int moveX[8]={0,1,2,1,0,-1,-2,-1};
int checkY[4]={-1,0,1,0};  //상우하좌에 사용(응시자 있으면 false)
int checkX[4]={0,1,0,-1}; 
using namespace std;
int check(vector<string> place){
    for(int i=0;i<5;i++){
        string s=place[i]; //한줄씩 가져오기
        for(int j=0;j<5;j++){
            char c=s[j];  //한칸씩 가져오기
            if(c=='P'){
                for(int k=0;k<4;k++){  //상우하좌에 응시자 있으면 무조건 false
                    int nextY=i+checkY[k];
                    int nextX=j+checkX[k];
                    if(nextY<0||nextY>=5||nextX<0||nextX>=5) continue;
                    if(place[nextY][nextX]=='P') return 0;
                }
                for(int k=0;k<8;k++){  //붙어있어도 만약 파티션이 있으면 괜찮은경우
                    int nextY=i+moveY[k];
                    int nextX=j+moveX[k];
                    if(nextY<0||nextY>=5||nextX<0||nextX>=5) continue;
                    if(place[nextY][nextX]=='P'){
                        if(k==0||k==2||k==4||k==6){ //상우하좌
                            int partitionY=(i+nextY)/2;
                            int partitionX=(j+nextX)/2;
                            if(place[partitionY][partitionX]!='X') return 0;  //
                        }
                        else{ //대각에 존재
                            if(!(place[i][nextX]=='X'&&place[nextY][j]=='X')) return 0;
                        }
                    }
                }
            }
        }
    }
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(int i=0;i<5;i++){
        answer.push_back(check(places[i]));
    }
    return answer;
}