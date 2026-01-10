import java.util.Queue;
import java.util.LinkedList;

class Solution {
    public int solution(int[][] maps) {
        int answer = bfs(maps);
        
        return answer;
    }
    
    public int bfs(int[][] maps) {
        int returnValue = -1;
        int width = maps[0].length;
        int height = maps.length;
        boolean[][] visited = new boolean[height][width];
        
        LinkedList<int[]> queue = new LinkedList();

        queue.add(new int[]{0,0,1});
        visited[0][0] = true;
        
        while(!queue.isEmpty()) {
            int[] index = queue.poll();
            int currentX = index[0];
            int currentY = index[1];
            int result = index[2];
            
            if(currentX == width - 1 && currentY == height - 1) {
                returnValue = result;
                break;
            }
            
            int value = maps[currentY][currentX];
            
            //위로 X 그대로 Y -1
            int upperY = currentY - 1;
            if(upperY >= 0 && !visited[upperY][currentX] && maps[upperY][currentX] == 1) {
                queue.add(new int[]{currentX, currentY-1, result + 1});
                visited[upperY][currentX] = true;
            }
            
            //오른쪽으로 0번 +1 1번 그대로
            int upperX = currentX + 1;
            if(upperX < width && !visited[currentY][upperX] && maps[currentY][upperX] == 1) {
                queue.add(new int[]{upperX, currentY, result + 1});
                visited[currentY][upperX] = true;
            }
            
            //왼쪽으로 0번 -1 1번 그대로
            int downerX = currentX - 1;
            if(downerX >= 0 && !visited[currentY][downerX] && maps[currentY][downerX] == 1) {
                queue.add(new int[]{downerX, currentY, result + 1});
                visited[currentY][downerX] = true;
            }
            
            //아래로 0번 +1 1번 그대로
            int downerY = currentY + 1;
            if(downerY < height && !visited[downerY][currentX] && maps[downerY][currentX] == 1) {
                queue.add(new int[]{currentX, downerY, result + 1});
                visited[downerY][currentX] = true;
            }
            
        }
        
        return returnValue;
    }
}