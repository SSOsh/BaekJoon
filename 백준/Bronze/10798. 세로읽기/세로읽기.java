import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[][] arr = new String[5][15];
        for(int i=0;i<5;i++) {
            String line = br.readLine();
            for(int j=0;j<15;j++) {
                if(line.length() > j) {
                    arr[i][j] = String.valueOf(line.charAt(j));
                }else {
                    arr[i][j] = "";
                }
            }
        }

        StringBuilder sb = new StringBuilder();
        for(int i=0;i<15;i++) {
            for(int j=0;j<5;j++) {
                sb.append(arr[j][i]);
            }
        }
        bw.write(sb.toString());

        br.close();
        bw.close();
    }
}