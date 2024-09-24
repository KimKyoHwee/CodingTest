import java.lang.*;
import java.io.*;
import java.util.*;
class Solution {
    int N;
    int[] answer;
    public boolean judge(String num, boolean flag) {  //flag=true면 이전에 부모에 0이있음
        //System.out.println(num+ " flag : "+flag);
        if(num.length()==1){
            if(flag&&num.charAt(0)=='1') return false;
            else return true;
        }
        int centerIndex = (num.length() + 1) / 2;  // 중간 인덱스 계산
        centerIndex--;
        String s1 = num.substring(0, centerIndex);  // 왼쪽 부분 문자열
        String s2 = num.substring(centerIndex+1, num.length());  // 오른쪽 부분 문자열
        if(num.charAt(centerIndex)=='0'){
            return judge(s1, true)&&judge(s2, true);
        }
        else{
            if(flag) return false;
            else return judge(s1, flag)&&judge(s2, flag);
        }
    }

    public String changeBinary(Long num) {
        StringBuilder result = new StringBuilder();
        while (num > 0) {
            result.append(num % 2 == 0 ? "0" : "1");
            num /= 2;
        }
    return result.reverse().toString();
    }
    
    public int[] solution(long[] numbers) {
        Set<Integer> lens=new HashSet<>();
        Long l=2L;
        for(int i=2;i<=64;i*=2){
            lens.add(i-1);
        }
        
        N=numbers.length;
        answer=new int[N];
        for(int i=0;i<N;i++){
            Long nowNum=numbers[i];
            String binary=changeBinary(nowNum);
            StringBuilder binaryNum=new StringBuilder(binary);
            while(true){
                int len=binaryNum.length();
                if(lens.contains(len)) break;
                else binaryNum.insert(0,"0");
            }
            //binaryNum.deleteCharAt(0);
            if(judge(binaryNum.toString(), false)) answer[i]=1;
        }
        return answer;
    }
}