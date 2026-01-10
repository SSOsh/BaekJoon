import java.util.*;

class Solution {
    // 상 하 좌 우
    public int[] moveX = {0, 0, -1, 1};
    public int[] moveY = {-1, 1, 0, 0};
    
    public int[] solution(String[][] places) {
        int[] answer = new int[places.length];
        
        for(int i=0;i<places.length;i++) {
            answer[i] = check(places[i]);
        }
        
        return answer;
    }
    
    public int check(String[] places) {
        for(int i=0;i<places.length;i++) {
            String col = places[i];
            for(int j=0;j<col.length();j++) {
                char value = col.charAt(j);
                
                if(value == 'P') {
                    int bfsResult = bfs(places, i, j);
                    if(bfsResult == 0) return 0;
                }
            }
        }
        
        return 1;
    }
    public int bfs(String[] places, int y, int x) {
        boolean[][] visited = new boolean[5][5];
        
        Queue<Character> valueQ = new LinkedList<>();
        Queue<Integer> depthQ = new LinkedList<>();
        Queue<Integer> XQ = new LinkedList<>();
        Queue<Integer> YQ = new LinkedList<>();
        
        valueQ.add(places[y].charAt(x));
        depthQ.add(0);
        XQ.add(x);
        YQ.add(y);
        visited[y][x] = true;
        
        while(!valueQ.isEmpty()) {
            char currentValue = valueQ.poll();
            int depth = depthQ.poll();
            int currentX = XQ.poll();
            int currentY = YQ.poll();
            
            if(currentValue == 'P' && depth <= 2 && depth != 0) {
                return 0;
            }
            
            for(int i=0;i<4;i++) {
                int moveXX = moveX[i] + currentX;
                int moveYY = moveY[i] + currentY;
                if(moveXX >= 0 && moveYY >= 0 && moveXX < 5 && moveYY < 5 && !visited[moveYY][moveXX] && places[moveYY].charAt(moveXX) != 'X') {
                    valueQ.add(places[moveYY].charAt(moveXX));
                    depthQ.add(depth + 1);
                    XQ.add(moveXX);
                    YQ.add(moveYY);
                    visited[moveYY][moveXX] = true;
                }
            }
        }
        
        return 1;
    }
}