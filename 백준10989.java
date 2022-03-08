import java.io.*;
import java.util.Arrays;

public class 백준10989 {
    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int[] arr;
        int n = 0;

        try {
            n = Integer.parseInt(br.readLine());
            arr = new int[n];
            for(int i=0;i<n;i++) {
                arr[i] = Integer.parseInt(br.readLine());
            }

            Arrays.sort(arr);

            for(int i=0;i<n;i++) {
               sb.append(arr[i] + "\n");
            }
            System.out.println(sb);
            br.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
