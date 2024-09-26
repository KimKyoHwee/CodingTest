import java.lang.*;
import java.io.*;
import java.util.*;
import java.util.Map.*;
import java.util.AbstractMap.*;
class Solution {
    public int maxWin;
    public int N;
    List<Integer> result;  //0번에서 시작하는 결과값 인덱스
    List<Map<Integer, Integer>> dices; //i번 map에 1~6중 주사위 값 갯수(1~6아닐수도있음)
    
    //지금까지 만들수 있는 값들의 map, 다음 주사위가 가지고 있는 값들의 map받아서 이제 만들 수 있는 값들의 map 리턴
    HashMap<Integer, Integer> calculate(Map<Integer, Integer> nowResult, Map<Integer, Integer> nextResult){
        if(nowResult.size()==0) return new HashMap<>(nextResult);
        HashMap<Integer, Integer> newResult=new HashMap<>();
        for(Map.Entry<Integer, Integer> nextEntry:nextResult.entrySet()){
            int nextIndex=nextEntry.getKey(); 
            int nextValue=nextEntry.getValue();
            for(Map.Entry<Integer, Integer> entry: nowResult.entrySet()){
                int nowIndex=entry.getKey();
                int nowValue=entry.getValue();
                newResult.putIfAbsent(nowIndex+nextIndex, 0);
                newResult.put(nowIndex+nextIndex, newResult.get(nowIndex+nextIndex)+(nowValue*nextValue));
            }
        }
        return newResult;
    }
    //조합 받아서 그 조합으로 만들수 있는 값들 Map만들고, 비교후 maxWin보다 많이이기면 true
    boolean judge(List<Integer> combi){ 
        Map<Integer, Integer> resultA=new HashMap<>();
        Map<Integer, Integer> resultB=new HashMap<>();
        boolean[] visited=new boolean[N*2];
        for(int i=0;i<combi.size();i++){
            int nowIndex=combi.get(i);
            resultA=calculate(resultA, dices.get(nowIndex));
            visited[nowIndex]=true;
        }
        for(int i=0;i<N*2;i++){
            if(visited[i]) continue;
            resultB=calculate(resultB, dices.get(i));
        }
        int nowWin=0;
        for(Map.Entry<Integer, Integer> aEntry:resultA.entrySet()){
            int aKey=aEntry.getKey(); //a의 값
            int aCnt=aEntry.getValue(); //그 값의 갯수
            for(Map.Entry<Integer, Integer> bEntry:resultB.entrySet()){
                int bKey=bEntry.getKey(); //a의 값
                int bCnt=bEntry.getValue(); //그 값의 갯수
                if(aKey<=bKey) continue;
                nowWin+=(aCnt*bCnt);
            }
        }
        if(nowWin>maxWin) {
            maxWin=nowWin;
            return true;
        }
        else return false;
    }
    
    void dfs(List<Integer> combi, int depth){
        if(combi.size()==N){
            if(judge(combi)) result=new ArrayList<>(combi);
            return;
        }
        if(combi.size()+(N*2-(depth))<N) return;
        List<Integer> copyCombi=new ArrayList<>(combi);
        dfs(copyCombi, depth+1); //이번 숫자 안넣고 넘기기
        copyCombi.add(depth);
        dfs(copyCombi, depth+1); //이번숫자 넣고 넘기기
    }

    public int[] solution(int[][] dice) {
        dices=new ArrayList<>();
        //각 주사위별로 나올수 있는 값 dices에 저장
        for(int i=0;i<dice.length;i++){
            dices.add(new HashMap<Integer, Integer>());
            for(int j=0;j<6;j++){  //i번째 dice j번째 면의 값
                int nowNum=dice[i][j];
                dices.get(i).putIfAbsent(nowNum, 0);
                dices.get(i).put(nowNum, dices.get(i).get(nowNum)+1);
            }
        }
        result=new ArrayList<>();
        N=dice.length/2;
        dfs(new ArrayList<Integer>(),0);
        int[] answer=new int[dice.length/2];
        for(int i=0;i<result.size();i++){
            answer[i]=result.get(i)+1;
        }
        return answer;
    }
}
