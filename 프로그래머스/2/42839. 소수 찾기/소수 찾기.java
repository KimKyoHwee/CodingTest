import java.lang.*;
import java.io.*;
import java.util.*;
class Solution {
    static Set<Integer> iS=new HashSet<Integer>();
    static boolean[] visited;
    static char[] inputs;
    public int solution(String numbers) {
        inputs=new char[numbers.length()];
        visited=new boolean[numbers.length()];
        for(int i=0;i<numbers.length();i++){
            inputs[i]=numbers.charAt(i);
            visited[i]=false;
        }
        dfs("", 0);
        int answer = iS.size();
        return answer;
    }
    public void dfs(String now, int index){
        if(now!=""){
            int nowNum=Integer.parseInt(now);
            if(eratos(nowNum)) {
                //System.out.println(nowNum);
                iS.add(nowNum);
            }
        }
        if(now.length()==visited.length) return;
        for(int i=0;i<inputs.length;i++){
            if(visited[i]) continue;
            visited[i]=true;
            dfs(now+inputs[i], index+1);
            visited[i]=false;
        }
    }
    public boolean eratos(int num){
        if(num<2) return false;
        for(int i=2;i*i<=num;i++){
            if((num%i)==0) return false;
        }
        return true;
    }
}