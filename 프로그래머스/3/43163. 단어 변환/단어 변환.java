import java.util.*;

class Solution {
    public static boolean[] visited;
    
    public int solution(String begin, String target, String[] words) {
        int answer = 0;
        visited = new boolean[words.length];
        
        answer = bfs(begin, target, words);
        
        return answer;
    }
    
    public int bfs(String begin, String target, String[] words) {
        Queue<String> stringQueue = new LinkedList<String>();
        Queue<Integer> depthQueue = new LinkedList<Integer>();
        
        stringQueue.add(begin);
        depthQueue.add(0);
        
        while(!stringQueue.isEmpty()) {
            String currentTarget = stringQueue.poll();
            int depth = depthQueue.poll();
            
            if(currentTarget.equals(target)) {
                return depth;
            }
            
            for(int i=0;i<words.length;i++) {
                int notMatchInt = 0;
                String matchedString = words[i];

                if(visited[i]) continue;

                for(int j=0;j<matchedString.length();j++) {
                    if(currentTarget.charAt(j) != matchedString.charAt(j)) {
                        notMatchInt++;
                    }
                }

                if(notMatchInt == 1) {
                    stringQueue.add(matchedString);
                    depthQueue.add(depth + 1);
                    visited[i] = true;
                }
            }
        }
        
        return 0;
    }
}