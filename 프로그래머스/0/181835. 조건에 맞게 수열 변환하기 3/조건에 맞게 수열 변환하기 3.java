class Solution {
    public int[] solution(int[] arr, int k) {
        for(int i=0;i<arr.length;i++) {
            // k더하기
            if(k % 2 == 0) {
                arr[i] += k;
            }
            // k곱하기
            else {
                arr[i] *= k;
            }    
        }
        
        return arr;
    }
}