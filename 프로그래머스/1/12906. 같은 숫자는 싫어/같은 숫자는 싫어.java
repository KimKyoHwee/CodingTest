import java.util.*;
import java.io.*;
import java.lang.*;

public class Solution {
    public int[] solution(int []arr) {
        Set<Integer> input=new HashSet<>();
        List<Integer> result=new ArrayList<>();
        int prev=arr[0];
        result.add(prev);
        for(int i=0;i<arr.length;i++){
            int nowNum=arr[i];
            if(prev!=nowNum){
                result.add(nowNum);
                prev=nowNum;
            }
        }
        int[] answer = new int[result.size()];
        for(int i=0;i<result.size();i++){
            answer[i]=result.get(i);
        }
        return answer;
    }
}