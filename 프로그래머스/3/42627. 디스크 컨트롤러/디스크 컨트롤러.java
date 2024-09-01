import java.util.*;
import java.util.Map.Entry;
import java.util.AbstractMap.SimpleEntry;

class Solution {
    public int solution(int[][] jobs) {
        int nowTime = 0;
        int totalWaitTime = 0;
        int completedJobs = 0;
        int jobIndex = 0;
        
        // 작업을 시작 시간 기준으로 오름차순 정렬
        Arrays.sort(jobs, new Comparator<int[]>() {
            @Override
            public int compare(int[] job1, int[] job2) {
                return Integer.compare(job1[0], job2[0]);
            }
        });
        
        PriorityQueue<Entry<Integer, Integer>> pq = new PriorityQueue<>(
            new Comparator<Entry<Integer, Integer>>() {
                @Override
                public int compare(Entry<Integer, Integer> e1, Entry<Integer, Integer> e2) {
                    return Integer.compare(e1.getValue(), e2.getValue()); // 소요 시간 기준 오름차순
                }
            }
        );

        while (completedJobs < jobs.length) {
            // 현재 시간 이전에 도착한 모든 작업을 큐에 추가
            while (jobIndex < jobs.length && jobs[jobIndex][0] <= nowTime) {
                pq.offer(new SimpleEntry<>(jobs[jobIndex][0], jobs[jobIndex][1]));
                jobIndex++;
            }
            
            if (pq.isEmpty()) { 
                // 큐가 비어 있으면 현재 시간 이후의 작업으로 이동
                nowTime = jobs[jobIndex][0];
            } else {
                // 가장 빨리 끝나는 작업을 선택
                Entry<Integer, Integer> job = pq.poll();
                nowTime += job.getValue();
                totalWaitTime += (nowTime - job.getKey());
                completedJobs++;
            }
        }
        
        return totalWaitTime / jobs.length; // 평균 대기 시간 반환
    }
}
