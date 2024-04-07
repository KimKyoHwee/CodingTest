import java.io.*;
import java.util.*;
import java.lang.*;
class Solution {
     public int howManyDayLeft(int progress, int speed){
        int leftProgress=100-progress;
        if(leftProgress==0) return 0;
        int result=leftProgress/speed;
        if(leftProgress%speed!=0) result++;
        return result;
    }
    public int[] solution(int[] progresses, int[] speeds) {
        List<Integer> answerList=new ArrayList<>();
        Queue<Integer> leftDay=new LinkedList<>();
        for(int i=0;i<progresses.length;i++){
            leftDay.add(howManyDayLeft(progresses[i], speeds[i]));
        }
        int turn=0;
        while(!leftDay.isEmpty()){
            int progressCnt=0;
            turn++;
            while(leftDay.peek()!=null&&leftDay.peek()<=turn){
                leftDay.poll();
                progressCnt++;
            }
            if(progressCnt!=0) answerList.add(progressCnt);
        }
        int[] answer=new int[answerList.size()];
        for(int i=0;i<answerList.size();i++) answer[i]=answerList.get(i);
        return answer;
    }
}