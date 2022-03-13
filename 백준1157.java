import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 백준1157 {
    public static void main(String[] args) throws IOException {
        String result = "";
        int[] dist = new int[27];
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        for(int i=0;i<str.length();i++) {
            if(str.charAt(i) >= 97) {
                dist[str.charAt(i) - 97]++;
            }else {
                dist[str.charAt(i) - 65]++;
            }
        }
        int max = 0, cnt = 0;
        for(int i=0;i<27;i++) {
            if((max < dist[i])) {
                max = dist[i];
                cnt = i;
            }
        }
        for(int i=0;i<27;i++) {
            if(i == cnt) continue;
            if(max == dist[i]) result = "?";
        }
        if(result.compareTo("?") != 0){
            result = Character.toString(cnt + 65);
        }
        System.out.println(result);
    }
}
