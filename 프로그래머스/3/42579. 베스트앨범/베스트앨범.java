import java.lang.*;
import java.io.*;
import java.util.*;
import java.util.Map.*;
import java.util.AbstractMap.*;
public class Music implements Comparable<Music>{
    int index;
    int playCnt;
    public Music(int index, int playCnt){
        this.index=index;
        this.playCnt=playCnt;
    }
    
    @Override
    public int compareTo(Music other){
        if(playCnt==other.playCnt) return Integer.compare(index, other.index);
        return Integer.compare(other.playCnt, playCnt);
    }
}
class Solution {
    Map<String, Integer> playCnt=new HashMap<>();
    Map<String, PriorityQueue<Music>> musics=new HashMap<>();
    public int[] solution(String[] genres, int[] plays) {
        List<Integer> answer = new ArrayList<>();
        for(int i=0;i<plays.length;i++){
            String genre=genres[i];
            int play=plays[i];
            playCnt.put(genre, playCnt.getOrDefault(genre, 0)+play);
            musics.putIfAbsent(genre, new PriorityQueue<Music>());
            musics.get(genre).offer(new Music(i, play));
        }
        List<Entry<String, Integer>> list=new ArrayList<>();
        for(Map.Entry<String, Integer> m : playCnt.entrySet()){
            list.add(new SimpleEntry(m.getKey(), m.getValue()));
        }
        Collections.sort(list, new Comparator<Entry<String, Integer>>(){
           @Override
            public int compare(Entry<String, Integer> a, Entry<String, Integer> b){
                return Integer.compare(b.getValue(), a.getValue());
            }
        });
        int index=0;
        for(int i=0;i<list.size();i++){
            Entry<String, Integer> entry=list.get(i);
            String s=entry.getKey();
            PriorityQueue<Music> pq=musics.get(s);
            int pqIndex=0;
            while(!pq.isEmpty()){
                Music now=pq.poll();
                answer.add(now.index);
                index++;
                pqIndex++;
                if(pqIndex==2) break;
            }
        }
        int[] result=new int[index];
        for(int i=0;i<index;i++) result[i]=answer.get(i);
        return result;
    }
}