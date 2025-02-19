import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int x = Integer.parseInt(br.readLine());
        int y = Integer.parseInt(br.readLine());
        int result = 0;
        if(x > 0 && y > 0) result += 1;
        if(x < 0 && y > 0) result += 2;
        if(x < 0 && y < 0) result += 3;
        if(x > 0 && y < 0) result += 4;

        System.out.println(result);

        br.close();
        bw.close();
    }


}