import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 백준4889 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int current;
        int order = 1;
        int cnt;
        String str;
        while(true) {
            current = 0;
            cnt = 0;
            str = br.readLine();
            if(str.contains("-")) break;
            for(int i=0;i<str.length();i++) {
                if(str.charAt(i) == '{') {
                    current++;
                }else {
                    if(current != 0) {
                        current--;
                    }else {
                        current++;
                        cnt++;
                    }
                }
            }
            if(current != 0) cnt += (current / 2);
            sb.append(order++);
            sb.append(". ");
            sb.append(cnt);
            sb.append("\n");
        }
        System.out.println(sb);
    }
}
