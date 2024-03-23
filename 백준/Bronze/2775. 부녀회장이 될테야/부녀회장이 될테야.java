import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
//        StringTokenizer st = new StringTokenizer(br.readLine());

        int[][] arr = new int[15][15];
        for (int i=1;i<15;i++) {
            arr[0][i] = i;
        }
        for(int i=1;i<15;i++) {
            for(int j=1;j<15;j++) {
                if(j==1) {
                    arr[i][j] = 1;
                    continue;
                }

                arr[i][j] = arr[i][j-1] + arr[i-1][j];
            }
        }

        int loop = Integer.parseInt(br.readLine());
        for(int i=0;i<loop;i++) {
            int x = Integer.parseInt(br.readLine());
            int y = Integer.parseInt(br.readLine());

            bw.write(arr[x][y] + "\n");
            bw.flush();
        }

        br.close();
        bw.close();
    }
}
