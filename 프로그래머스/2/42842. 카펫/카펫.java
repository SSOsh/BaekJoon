class Solution {
    public int[] solution(int brown, int yellow) {
        int[] answer = {};
        
        int total = brown + yellow;
        
        for(int i=1;i<total;i++) {
            int x = total / i;
            if(total % i != 0) continue;
            
            if((x - 2) * (i - 2) == yellow) {
                answer = new int[]{x, i};
                break;
            }
        }
        
        return answer;
    }
}