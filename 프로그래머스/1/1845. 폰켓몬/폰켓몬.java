import java.lang.*;
import java.io.*;
import java.util.*;
class Solution {
    public static Set<Integer> input=new HashSet<Integer>();
    public int solution(int[] nums) {
        int answer = 0;
        for(int i=0;i<nums.length;i++){
            input.add(nums[i]);
        }
        answer=input.size();
        if(answer>(nums.length/2)) answer=nums.length/2;
        return answer;
    }
}