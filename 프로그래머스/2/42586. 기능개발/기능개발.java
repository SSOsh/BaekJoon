import java.util.*;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        List<Integer> result = new ArrayList<>();
        int[] answer;
        int[] times = new int[100];
        for(int i=0;i<speeds.length;i++) {
            int progress = progresses[i];
            int speed = speeds[i];
            if((100-progress) % speed != 0) {
                times[i] = ((100 - progress) / speed) + 1;
            }else {
                times[i] = ((100 - progress) / speed);
            }
        }
        // ex) 문제 1번 (100-93)/1 = 7 , ((100-30)/30)+1 = 3 , (100-55)/5 = 9
        
        int temp = 1;
        int maxTemp = times[0];
        for(int i=1;i<speeds.length;i++) {
            if(maxTemp >= times[i]) {
                temp++;
                continue;
            }
            
            result.add(temp);
            maxTemp = times[i];
            temp = 1;
        }
        
        if(maxTemp != 0) {
            result.add(temp);
        }
        
        answer = new int[result.size()];
        for(int i=0;i<result.size();i++) {
            answer[i] = result.get(i);
        }
        
        return answer;
    }
}