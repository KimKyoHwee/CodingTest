import java.lang.*;
import java.io.*;
import java.util.*;
class Solution {
    public static Set<String> dict=new HashSet<>();
    public boolean solution(String[] phone_book) {
        Arrays.sort(phone_book, new Comparator<String>(){
            @Override
            public int compare(String s1, String s2){
                return Integer.compare(s2.length(), s1.length());
            }
        });
        for(int i=0;i<phone_book.length;i++){
            String now=phone_book[i];
            if(dict.contains(now)) return false;
            for(int j=0;j<now.length();j++){
                String sub=now.substring(0,j+1);
                dict.add(sub);
            }
        }
        boolean answer = true;
        return answer;
    }
}