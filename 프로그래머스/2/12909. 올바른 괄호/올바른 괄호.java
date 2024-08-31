import java.lang.*;
import java.io.*;
import java.util.*;

class Solution {
    public static Stack<Character> st=new Stack<>();
    boolean solution(String s) {
        boolean answer = true;
        for(int i=0;i<s.length();i++){
            char now=s.charAt(i);
            st.push(now);
        }
        int closeCnt=0;
        while(!st.isEmpty()){
            char now=st.pop();
            if(now=='('){
                closeCnt--;
                if(closeCnt<0){
                    answer=false;
                    break;
                }
            }
            else closeCnt++;
        }
        if(closeCnt!=0) answer=false;
        return answer;
    }
}