import java.util.*;

class Solution {
    public int solution(int k, int[] tangerine) {
        int answer = 0;
        
        int[] check = new int[10000001];
        
        for(int i=0;i<tangerine.length;i++) {
            check[tangerine[i] - 1]++;
        }
        
        Arrays.sort(check);
        
        for(int i=check.length - 1;i>=0;i--) {
            k = k - check[i];
            answer++;
            if(k <= 0) {
                break;
            }
        }
        
        return answer;
    }
}