import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
//        StringTokenizer st = new StringTokenizer(br.readLine());

        int[] arr = new int[1000];
        arr[0] = 1;
        arr[1] = 2;
        arr[2] = 3;
        arr[3] = 5;
        arr[4] = 8;
        int num = Integer.parseInt(br.readLine());

        for(int i=5;i<1000;i++) {
            arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
        }

        bw.write(arr[num-1] + "");
        br.close();
        bw.close();
    }
}
