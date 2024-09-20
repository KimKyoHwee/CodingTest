import java.lang.*;
import java.io.*;
import java.util.*;
import java.util.Map.*;
import java.util.AbstractMap.*;
class Solution {
    String[] answer;
    int N;
    public boolean judge(List<String> result){
        //for(int i=0;i<N+1;i++) System.out.print(result.get(i));
        if(answer[0]==null) return true;
        for(int i=0;i<N+1;i++){
            String answerS=answer[i];
            String resultS=result.get(i);
            int comp=answerS.compareTo(resultS);
            if(comp==0) continue;
            if(comp<0) return false;  //앞에께 사전적으로 먼저임
            else return true;
        }
        return false;
    }
    public void dfs(String start, Map<String, ArrayList<String>> input, List<String> result) {
        //for(int i=0;i<result.size();i++) System.out.print(result.get(i)+" , ");
        //System.out.println();
    // DFS 종료 조건
    if (result.size() == N + 1) {
        System.out.println("dd");
        if (judge(result)) {
            for (int i = 0; i < N + 1; i++) answer[i] = result.get(i);
        }
        return;
    }

    // 결과 리스트 얕은 복사
    List<String> copyResult = new ArrayList<>(result);
    
    // input 맵의 얕은 복사 (ArrayList까지 복사)
    Map<String, ArrayList<String>> copyInput = new HashMap<>();
    for (Map.Entry<String, ArrayList<String>> entry : input.entrySet()) {
        copyInput.put(entry.getKey(), new ArrayList<>(entry.getValue()));
    }
        

    // 현재 경로에 추가
    copyResult.add(start);
        if (copyResult.size() == N + 1) {
        if (judge(copyResult)) {
            for (int i = 0; i < N + 1; i++) answer[i] = copyResult.get(i);
        }
        return;
    }

    // 탐색 경로 설정
    copyInput.putIfAbsent(start, new ArrayList<>());
    for (int i = 0; i < copyInput.get(start).size(); i++) {
        String next = copyInput.get(start).get(0);  // 첫 번째 경로
        copyInput.get(start).remove(0);             // 경로에서 제거
        if(result.size()==0) System.out.print(next+", "+copyResult);
        dfs(next, copyInput, copyResult);           // 재귀 호출
        copyInput.get(start).add(next);             // 경로 원복
    }
}

    public String[] solution(String[][] tickets) {
        N=tickets.length;
        answer=new String[N+1];
        Map<String, ArrayList<String>> input=new HashMap<String, ArrayList<String>>();
        for(int i=0;i<tickets.length;i++){
            String start=tickets[i][0];
            String end=tickets[i][1];
            input.putIfAbsent(start, new ArrayList<String>());
            input.get(start).add(end);
        }
        dfs("ICN", input, new ArrayList<String>());
        return answer;
    }
}