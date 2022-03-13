import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 백준2789 {
    public static void main(String[] args) throws IOException {
        String str;
        String delete = new String("CAMBRIDGE");
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        str = br.readLine();
        for(int i=0;i<delete.length();i++) {
            str = str.replaceAll(String.valueOf(delete.charAt(i)), "");
        }
        System.out.println(str);
    }
}
