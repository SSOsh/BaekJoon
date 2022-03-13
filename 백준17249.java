import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class 백준17249 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        String dist = "(^0^)";
        int val1 = 0, val2 = 0;
        int location = str.indexOf(dist);
        for(int i=0;i<str.length();i++) {
            if(i < location) {
                if(String.valueOf(str.charAt(i)).compareTo("@") == 0) {
                    val1++;
                }
            }else if(i > location + 4) {
                if(String.valueOf(str.charAt(i)).compareTo("@") == 0) {
                    val2++;
                }
            }
        }
        StringBuilder sb = new StringBuilder();
        sb.append(val1);
        sb.append(" ");
        sb.append(val2);
        System.out.println(sb.toString());
    }
}
