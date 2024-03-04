#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
//전역변수
struct Keypad{
    int y;
    int x;
    Keypad(int inputY, int inputX) : y(inputY), x(inputX){}
    Keypad() {y=-1; x=-1;}
};
vector<int> leftHandNum={1,4,7};
vector<int> rightHandNum={3,6,9};
//전역변수 종료
Keypad numToKeypad(int num){
    if(num==0) return Keypad(3,1);
    num--;
    Keypad keypad;
    keypad.y=num/3;
    keypad.x=num%3;
    return keypad;
}
int getDistance(Keypad hand, Keypad num){
    return abs(hand.y-num.y)+abs(hand.x-num.x);
}
string solution(vector<int> numbers, string hand) {
    string answer = "";
    Keypad left=Keypad(3,0);
    Keypad right=Keypad(3,2);
    char flag='r';
    if(hand=="left") flag='l';
    cout<<"hand: "<<flag<<"\n"; 
    for(int i=0;i<numbers.size();i++){
        Keypad handKeyPad=numToKeypad(numbers[i]);  //들어온 숫자 위치 구하기
        //147이 들어오면 왼손처리 369가 들어오면 오른손처리
        bool escapeBigLoop=false;
        for(int j=0;j<leftHandNum.size();j++){
            if(numbers[i]==leftHandNum[j]){
                escapeBigLoop=true;
                answer+='L';
                left=handKeyPad;
                break;
            }
            else if(numbers[i]==rightHandNum[j]){
                escapeBigLoop=true;
                answer+='R';
                right=handKeyPad;
                break;
            }
        }
        if(escapeBigLoop) continue;
        //147 왼손처리 369 오른손처리 종료
        int leftDistance=getDistance(left, handKeyPad);
        int rightDistance=getDistance(right, handKeyPad);
        if(leftDistance>rightDistance){
            answer+='R';
            right=handKeyPad;
        }
        else if(leftDistance<rightDistance){
            answer+='L';
            left=handKeyPad;
        }
        else{
            if(flag=='r'){
                answer+='R';
                right=handKeyPad;
            }
            else{
                answer+='L';
                left=handKeyPad;
            }
        }
    }
    return answer;
}