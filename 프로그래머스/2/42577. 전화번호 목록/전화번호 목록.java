import java.util.*;

class Solution {
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        
        Arrays.sort(phone_book);
        
        for(int i=0;i<phone_book.length - 1;i++) {
            String currentValue = phone_book[i];
            String nextValue = phone_book[i + 1];
            
            if(nextValue.startsWith(currentValue)) {
                return false;
            }
        }
        
        return answer;
    }
    
    // String length 가 짧은 순으로 sorting
    // 이중 for문 돌면서 상위 for i, 하위 for j 로 만든 후 j는 i보다 크게
    // 상위 phone_book[i]가 phone_book[j]의 처음 값과 같은지 확인
    // 맞다면 바로 return false; 아니라면 다음 for 순회
    // answer는 처음에 true 초기화.
}