import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int[] list = new int[3];
        for(int i=0;i<3;i++) {
            list[i] = Integer.parseInt(st.nextToken());
        }
        list = Arrays.stream(list).sorted().toArray();

        for(int i=0;i<3;i++) {
            System.out.print(list[i]);
            if(i != 2) {
                System.out.print(" ");
            }
        }
        br.close();
    }
}
