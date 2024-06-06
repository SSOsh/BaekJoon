class Solution {
    boolean solution(String s) {
        int open = 0;
        boolean answer = true;
        String first = Character.toString(s.charAt(0));
        if(!first.equals("(")) {
            answer = false;
        }else {
            for(int i=0;i<s.length();i++) {
                if(open < 0) {
                    answer = false;
                    break;
                }
                if(Character.toString(s.charAt(i)).equals("(")) {
                    open++;
                }else {
                    open--;
                }
            }
        }

        if(open != 0 && answer) {
            answer = false;
        }

        return answer;
    }
}