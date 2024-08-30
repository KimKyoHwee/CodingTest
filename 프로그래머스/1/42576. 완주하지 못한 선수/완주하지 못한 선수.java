import java.lang.*;
import java.util.*;
import java.io.*;
class Solution {
    public static Map<String, Integer> names=new HashMap<>();
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        for(int i=0;i<participant.length;i++){
            String nowName=participant[i];
            names.put(nowName, names.getOrDefault(nowName, 0)+1);
        }
        for(int i=0;i<completion.length;i++){
            String nowName=completion[i];
            names.put(nowName, names.getOrDefault(nowName, 0)-1);
        }
        for(Map.Entry<String, Integer> now:names.entrySet()){
            if(now.getValue()==1){
                answer=now.getKey();
                break;
            }
        }
        return answer;
    }
}