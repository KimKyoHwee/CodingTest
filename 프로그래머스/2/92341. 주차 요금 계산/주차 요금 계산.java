import java.io.*;
import java.lang.*;
import java.util.*;
class Solution {
    public static int calculateAnswer(int finalMin,int a, int b ,int perTime, int pee){
        //차가 들어온시간, 나간시간, 기본시간, 기본요금, 단위시간, 단위요금
		
        if(finalMin<=a) return b;
        finalMin-=a;
		int payTime=finalMin/perTime;
		if(finalMin%perTime!=0) payTime++;
		return b+(payTime*pee);
	}
    public static int calculateTime(String inTime, String outTime){
        int finalMin=0;
		int inTimeH=Integer.parseInt(inTime.substring(0,2));
		int outTimeH=Integer.parseInt(outTime.substring(0,2));
		int inTimeM=Integer.parseInt(inTime.substring(3,5));
		int outTimeM=Integer.parseInt(outTime.substring(3,5));
		int minusM=outTimeM-inTimeM;
		if(minusM<0){
			outTimeH--;
			finalMin+=(60+minusM);
		}
		else{
			finalMin+=minusM;
		}
		finalMin+=(outTimeH-inTimeH)*60;
        return finalMin;
    }
    public int[] solution(int[] fees, String[] records) {
		Map<Integer, String> h1=new HashMap<Integer, String>();
		Map<Integer, Integer> h2=new HashMap<Integer, Integer>();
		for(int i=0;i<records.length;i++){ //records돌면서
			String s=records[i];  //record한개 꺼내고
			String time=s.substring(0,5);  //시간파싱
			int carNum=Integer.parseInt(s.substring(6,10));  //차번호 파싱
			if(h1.containsKey(carNum)){ //h1에 이미 차가 들어가있으면
				int result=calculateTime(h1.get(carNum), time); //주차요금 정산
				if(h2.containsKey(carNum)){
                    h2.replace(carNum, (h2.get(carNum)+result)); //h2에 주차시간 더해주거나
                }
				else h2.put(carNum, result); //h2에 주차시간 내역 없으면 추가해주기
				h1.remove(carNum, h1.get(carNum));  //이후 h1에서 차량 제거
			}
			else{ //h1에 차가 없으면 추가해주기
				h1.put(carNum, s);
			}
		}
        for(Integer key:h1.keySet()){  //빠져나가지 않은 차량 처리
            int carNum=key;
            System.out.println("남은차 번호 : "+carNum+" 들어온 시간 : "+h1.get(carNum));
            int result= calculateTime(h1.get(key), "23:59");
            if(h2.containsKey(carNum)){
                h2.replace(carNum, (h2.get(carNum)+result)); //h2에 주차시간 더해주거나
            }
			else h2.put(carNum, result); //h2에 주차시간 내역 없으면 추가해주기
        }
        
		//h2 오름차순 정렬
		// List<Map.Entry<Integer, Integer>> entryList=new LinkedList<>(h2.entrySet());
		// entryList.sort(new Comparator<Map.Entry<Integer, Integer>>(){
		// 	@Override
		// 	public int compare(Map.Entry<Integer, Integer> o1, Map.Entry<Integer, Integer> o2){
		// System.out.println("o1: "+o1.getKey()+" o2: "+o2.getKey());
		// 		return o1.getKey()-o2.getKey();
		// 	}
		// }); //정렬완료(키의 오름차순)
        Map<Integer, Integer> h3=new TreeMap<>(h2);
		List<Integer> arr=new LinkedList<>();
		for(Integer key:h3.keySet()){
            System.out.println(key);
            arr.add(calculateAnswer(h3.get(key), fees[0], fees[1], fees[2], fees[3]));
		}
        int[] answer=new int[arr.size()];
        for(int i=0;i<answer.length;i++) answer[i]=arr.get(i);
		return answer;
    }
}