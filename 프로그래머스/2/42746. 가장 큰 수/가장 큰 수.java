import java.util.*;

class Solution {
    public String solution(int[] numbers) {
        // numbers 배열을 문자열 배열로 변환
        String[] strNumbers = new String[numbers.length];
        for (int i = 0; i < numbers.length; i++) {
            strNumbers[i] = String.valueOf(numbers[i]);
        }
        
        // 문자열 배열을 정렬
        Arrays.sort(strNumbers, new Comparator<String>() {
            @Override
            public int compare(String a, String b) {
                // 두 문자열을 이어 붙여 비교
                String order1 = a + b;
                String order2 = b + a;
                return order2.compareTo(order1); // 내림차순 정렬
            }
        });
        
        // 정렬된 문자열을 합쳐서 결과를 만듦
        StringBuilder answer = new StringBuilder();
        for (String str : strNumbers) {
            answer.append(str);
        }
        
        // 예외 처리: 만약 가장 큰 수가 0으로 시작하면, "0"을 반환 (즉, 모든 숫자가 0인 경우)
        if (answer.charAt(0) == '0') {
            return "0";
        }
        
        return answer.toString();
    }
}
