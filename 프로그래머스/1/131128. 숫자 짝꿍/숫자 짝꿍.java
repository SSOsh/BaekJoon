class Solution {
    public String solution(String X, String Y) {

        int[] aArr = new int[10];
        int[] bArr = new int[10];
        StringBuilder result = new StringBuilder(30000000);

        for (int i=0;i<X.length();i++) {
            int value = X.charAt(i) - '0';
            aArr[value]++;
        }

        for (int i=0;i<Y.length();i++) {
            int value = Y.charAt(i) - '0';
            bArr[value]++;
        }

        for (int i = 9;i > -1;i--) {
            int minValue = aArr[i] > bArr[i] ? bArr[i] : aArr[i];
            if(result.length() == 0 && i == 0 && minValue != 0) {
                result.append("0");
                break;
            }

            result.append(Integer.toString(i).repeat(minValue));
        }

        if(result.length() == 0) {
            result.append("-1");
        }
        
        return result.toString();
    }
}