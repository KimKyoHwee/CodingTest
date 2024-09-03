import java.lang.*;
import java.io.*;
import java.util.*;
class Solution {
    public static int[] first={1,2,3,4,5};
    public static int[] second={2,1,2,3,2,4,2,5};
    public static int[] third={3,3,1,1,2,2,4,4,5,5};
    public int[] solution(int[] answers) {
        int fSum=0, sSum=0, tSum=0;
        for(int i=0;i<answers.length;i++){
            int now=answers[i];
            int fNum=i%5, sNum=i%8, tNum=i%10;
            if(now==first[fNum]) fSum++;
            if(now==second[sNum]) sSum++;
            if(now==third[tNum]) tSum++;
        }
        int maxSum=Math.max(fSum, sSum);
        maxSum=Math.max(maxSum, tSum);
        int answerSize=0;
        if(maxSum==fSum) answerSize++;
        if(maxSum==sSum) answerSize++;
        if(maxSum==tSum) answerSize++;
        int[] answer = new int[answerSize];
        int answerIndex=0;
        if(maxSum==fSum) {
            answer[answerIndex]=1;
            answerIndex++;
        }
        if(maxSum==sSum) {
            answer[answerIndex]=2;
            answerIndex++;
        }
        if(maxSum==tSum) {
            answer[answerIndex]=3;
            answerIndex++;
        }
        return answer;
    }
}