import java.lang.*;
import java.io.*;
import java.util.*;
class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        for(int i=0;i<commands.length;i++){
            LinkedList<Integer> iL=new LinkedList<>();
            for(int j=commands[i][0]-1;j<commands[i][1];j++){
                iL.add(array[j]);
            }
            Collections.sort(iL);
            answer[i]=iL.get(commands[i][2]-1);
        }
        return answer;
    }
}