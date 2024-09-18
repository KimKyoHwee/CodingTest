import java.lang.*;
import java.io.*;
import java.util.*;
class Solution {
    public boolean pandan(int distance, int n, int mid, int[] rocks) {
        int prev = 0; // 이전 바위 위치 (시작점 0)
        int removeRocks = 0; // 제거한 바위 개수
        for (int rock : rocks) {
            if (rock - prev < mid) {
                // 현재 바위와 이전 바위 사이의 거리가 mid보다 작으면 바위 제거
                removeRocks++;
            } else {
                // 거리가 mid 이상이면 이전 바위 위치를 현재 바위 위치로 업데이트
                prev = rock;
            }
        }
        // 마지막 거리도 체크 (목표 지점 distance까지)
        if (distance - prev < mid) {
            removeRocks++;
        }
        // 제거한 바위 개수가 n개 이하인지 확인
        return removeRocks <= n;
    }
    public int parametric(int left, int right, int distance, int n, int[] rocks){
        if(left==right) return left;
        int mid=(left+right+1)/2;
        if(pandan(distance, n, mid, rocks)) return parametric(mid, right, distance, n, rocks);
        else return parametric(left, mid-1, distance, n, rocks);
    }
    public int solution(int distance, int[] rocks, int n) {
        Arrays.sort(rocks);
        int answer=parametric(1, distance, distance, n, rocks);
        return answer;
    }
}