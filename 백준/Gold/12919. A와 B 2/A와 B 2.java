import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static String s;
    public static String tt;
    public static int sLength;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        s = br.readLine();
        sLength = s.length();
        tt = br.readLine();


        if (dfs(tt)) {
            System.out.println(1);
        }else {
            System.out.println(0);
        }

        br.close();
    }

    public static boolean dfs(String t) {
        if(t.length() == sLength) {
            return t.equals(s);
        }

        if(t.charAt(t.length() - 1) == 'A') {
            if(dfs(t.substring(0, t.length() - 1))) {
                return true;
            }
        }
        if(t.charAt(0) == 'B') {
            StringBuilder sb = new StringBuilder(t.substring(1));
            return dfs(sb.reverse().toString());
        }

        return false;
    }
}
