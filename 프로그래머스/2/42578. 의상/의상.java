import java.util.*;
import java.util.stream.*;

class Solution {
    public int solution(String[][] clothes) {
        int answer = 0;
        Map<String, Integer> map = new HashMap<String, Integer>();
        for(int i=0;i<clothes.length;i++) {
            String[] cloth = clothes[i];
            if(map.containsKey(cloth[1])) {
                map.put(cloth[1], map.get(cloth[1]) + 1);
            }else {
                map.put(cloth[1], 1);
            }
        }
        
        List<Integer> result = map.values().stream().collect(Collectors.toList());
        
        answer = result.get(0) + 1;
        for(int i=1;i<result.size();i++) {
            answer *= result.get(i) + 1;
        }
        answer--;
        
        return answer;
    }
}