import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class 백준2178 {
    static boolean[][] visited;
    static int[][] arr;
    static int[] moveX = {-1, 1, 0, 0};
    static int[] moveY = {0, 0, -1, 1};
    static int n, m;
    public static void bfs(int x, int y) {
        LinkedList<int[]> queue = new LinkedList<>();
        queue.add(new int[] {x,y});

        while(!queue.isEmpty()) {
            int[] current = queue.poll();
            int currentX = current[0];
            int currentY = current[1];


            for(int i=0;i<4;i++) {
                int nextX = moveX[i] + currentX;
                int nextY = moveY[i] + currentY;
                if(nextX < 0 || nextX >= n || nextY < 0 || nextY >= m) {
                    continue;
                }
                if(visited[nextX][nextY] || arr[nextX][nextY] == 0) {
                    continue;
                }

                arr[nextX][nextY] = arr[currentX][currentY] + 1;
                visited[nextX][nextY] = true;
                queue.add(new int[] {nextX, nextY});
            }
        }
    }

    public static void main(String[] args) {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try {
            StringTokenizer st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            arr = new int[n][m];
            visited = new boolean[n][m];
            for(int i=0;i<n;i++) {
                st = new StringTokenizer(br.readLine());
                String value = st.nextToken();
                for(int j=0;j<m;j++) {
                    arr[i][j] = Integer.parseInt(String.valueOf(value.charAt(j)));
                }
            }
            bfs(0, 0);
            System.out.println(arr[n - 1][m - 1]);
        }
        catch(Exception e) {
            e.printStackTrace();
        }
    }
}
