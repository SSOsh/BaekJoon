import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
//        StringTokenizer st = new StringTokenizer(br.readLine());


        // arr[n] = arr[n-1] + arr[n-2] + arr[n-3]
        // arr[n] = arr[n-1]에서 + 1한 경우 && arr[n-2]에서 + 2한 경우 && arr[n-3]에서 + 3한 경우
        int[] arr = new int[12];
        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 2;
        arr[3] = 4;

        for (int i=4;i<11;i++) {
            arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
        }

        int rep = Integer.parseInt(br.readLine());
        for(int i=0;i<rep;i++) {
            int num = Integer.parseInt(br.readLine());
            bw.write(arr[num] + "\n");
            bw.flush();
        }

        br.close();
        bw.close();
    }
}
