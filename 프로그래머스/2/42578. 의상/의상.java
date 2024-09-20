import java.lang.*;
import java.io.*;
import java.util.*;
import java.util.Map.*;
import java.util.AbstractMap.*;
class Solution {
    public int solution(String[][] clothes) {
        Map<String, ArrayList<String>> input=new HashMap<>();
        int answer = 0;
        for(int i=0;i<clothes.length;i++){
            String value=clothes[i][0];
            String key=clothes[i][1];
            input.putIfAbsent(key, new ArrayList<String>());
            input.get(key).add(value);
        }
        ArrayList<Integer> clothCnt= new ArrayList<>();
        for(Map.Entry<String, ArrayList<String>> cloth : input.entrySet()){
            clothCnt.add(cloth.getValue().size());
        }
        int plus=1;
        for(int i=0;i<clothCnt.size();i++) plus*=(clothCnt.get(i)+1);
        
        answer+=plus;
        
        return answer-1;
    }
}