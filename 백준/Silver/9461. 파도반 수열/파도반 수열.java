import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
//        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(br.readLine());

        long[] arr = new long[101];

        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 1;
        arr[3] = 1;
        arr[4] = 2;


        for(int i=5;i<101;i++) {
            arr[i] = arr[i - 1] + arr[i - 5];
        }

        for(int i=0;i<n;i++) {
            int num = Integer.parseInt(br.readLine());
            bw.write(arr[num] + "\n");
            bw.flush();
        }

        br.close();
        bw.close();
    }
}