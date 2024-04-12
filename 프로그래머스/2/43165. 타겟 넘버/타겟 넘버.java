import java.lang.*;
import java.util.*;
import java.io.*;

class Solution {
    public static int answer=0;
    public static void dfs(int[] numbers, int target, int level, int sum){
        if(level==(numbers.length-1)){
            int sum1=sum+numbers[level];
            int sum2=sum-numbers[level];
            if(sum1==target||sum2==target) answer++;
            return;
        }
        dfs(numbers, target, level+1, sum+numbers[level]);
        dfs(numbers, target, level+1, sum-numbers[level]);
    }
    public int solution(int[] numbers, int target) {
        dfs(numbers, target, 0,0);
        return answer;
    }
}