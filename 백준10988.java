import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 백준10988 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int result = 1;
        for (int i = 0; i < str.length() / 2; i++) {
            if (String.valueOf(str.charAt(i)).compareTo(String.valueOf(str.charAt(str.length() - i - 1))) != 0) {
                result = 0;
            }
        }
        System.out.println(result);
    }
}
