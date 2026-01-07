class Solution {
    public int solution(int[] wallet, int[] bill) {
        int answer = 0;
        int tmp = 0;
        while(true) {
            int smallW = wallet[0] > wallet[1] ? wallet[1] : wallet[0];
            int bigW = wallet[0] > wallet[1] ? wallet[0] : wallet[1];
            int smallB = bill[0] > bill[1] ? bill[1] : bill[0];
            int bigB = bill[0] > bill[1] ? bill[0] : bill[1];
            
            if(smallW >= smallB && bigW >= bigB) {
                answer = tmp;
                break;
            }
            
            if(bill[0] > bill[1]) {
                bill[0] /= 2;
            }else {
                bill[1] /= 2;
            }
            tmp++;
        }
        
        return answer;
    }
}