import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String input = br.readLine();
        String[] list = input.split(" ");

        long result = 0;

        for (String s : list) {
            long tmp = 0;
            for (int i=0;i<s.length();i++) {
                tmp *= 10;
                tmp += Integer.parseInt(s.substring(i, i + 1));
            }
            result += tmp;
        }

        System.out.println(result);

        br.close();
        bw.close();
    }


}