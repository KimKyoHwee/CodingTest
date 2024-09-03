import java.lang.*;
import java.io.*;
import java.util.*;
class Solution {
    public int[] solution(int brown, int yellow) {
        int[] answer = new int[2];
        for(int i=3;i<=brown;i++){
            for(int j=3;j<=i;j++){
                if(check(j,i,brown,yellow)){
                    answer[0]=i;
                    answer[1]=j;
                    return answer;
                }
            }
        }
        return answer;
    }
    
    public boolean check(int resultY, int resultX, int brown, int yellow){
        int checkYellow=(resultY-2)*(resultX-2);
        int checkBrown=(2*resultY)+(2*resultX)-4;
        if(yellow==checkYellow&&brown==checkBrown) return true;
        return false;
    }
}
