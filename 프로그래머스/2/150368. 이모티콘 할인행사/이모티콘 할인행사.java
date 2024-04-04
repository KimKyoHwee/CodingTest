import java.util.*;
import java.io.*;

class Solution {
    public static int[] sale={10,20,30,40};  //할인률
    public static List<Integer> usersWantSale=new ArrayList<>();  //각 사용자들이 원하는 할인률
    public static int[][] priceWithSale; //할인율 들어간 이모티콘 가격 미리 저장
    public static int[] answer;
    
    public void dfs(int[][] users, int level, int maxLevel, int[] saleList){  
        //level : dfs단계(여기선 이모티콘 갯수가 max), saleList : 지금까지 저장한 이모티콘별 할인율(0~4)
        if(level==maxLevel){   //마지막 이모티콘까지 할인율 정해짐
            int memberSum=0; //임티플 가입자 수
            int allEmoSum=0; //유저 전체가 임티 가입에 쓴 돈
            for(int i=0;i<users.length;i++){ //유저 돌기
                int nowPer=users[i][0];   //이번 유저 구매기준 할인율
                int nowPrice=users[i][1];  //이번 유저 임티플 구매 마지노선
                int emoSum=0; //이번 유저가 이모티콘 구매에 쓴 총가격
                for(int j=0;j<saleList.length;j++){  //이모티콘 돌면서 구매한거 가격 계산
                    if((saleList[j]+1)*10>=nowPer){ //할인율이 이번 유저 기준보다 높으면
                        int emoPrice=priceWithSale[j][saleList[j]]; //j번째 이모티콘 할인된가격
                        emoSum+=emoPrice;
                    }
                }//이번 유저가 구매한 이모티콘 총 가격 정리완료
                if(emoSum>=nowPrice) {  //이번 유저가 정해둔 마지노선보다 임티가격이 비싸면 임티 안사고 임티플 가입
                    memberSum++;
                }
                else allEmoSum+=emoSum;  //마지노선 넘으면 그냥 임티 구매 가격만 추가
            }
            if(answer[0]<memberSum){
                answer[0]=memberSum;
                answer[1]=allEmoSum;
            } 
            else if(answer[0]==memberSum&&answer[1]<allEmoSum){
                answer[0]=memberSum;
                answer[1]=allEmoSum;
            }
        }
        else{
            for(int i=0;i<4;i++){
                saleList[level]=i;
                dfs(users, level+1, maxLevel, saleList);
            }
        }
    }
    
    public int[] solution(int[][] users, int[] emoticons) {
        answer= new int[2];
        Arrays.fill(answer, 0);
        //할인율 미리 적용한 가격 저장해두기
        priceWithSale=new int[emoticons.length][4];
        for(int i=0;i<emoticons.length;i++){
            for(int j=0;j<4;j++){
                priceWithSale[i][j]=emoticons[i]-(emoticons[i]*sale[j]/100);
            }
        } //할인율 미리 저장 완료
        int[] saleList=new int[emoticons.length];
        Arrays.fill(saleList, 0);
        dfs(users, 0, emoticons.length, saleList);
        return answer;
    }
}