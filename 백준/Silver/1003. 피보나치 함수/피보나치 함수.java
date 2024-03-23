import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
//        StringTokenizer st = new StringTokenizer(br.readLine());

        int rep = Integer.parseInt(br.readLine());

        Integer[][] arr = new Integer[41][2];
        //0
        arr[0][0] = 1;
        arr[0][1] = 0;
        //1
        arr[1][0] = 0;
        arr[1][1] = 1;
        for(int tot = 0;tot<rep;tot++){
            int num = Integer.parseInt(br.readLine());
            if(arr[num][0] == null && arr[num][1] == null) {
                for(int i=2;i<=num;i++) {
                    if(arr[i][0] != null && arr[i][1] != null) continue;
                    arr[i][0] = arr[i - 1][0] + arr[i - 2][0];
                    arr[i][1] = arr[i - 1][1] + arr[i - 2][1];
                }
            }

            bw.write(arr[num][0] + " " + arr[num][1] + "\n");
            bw.flush();
        }

        br.close();
        bw.close();
    }
}
