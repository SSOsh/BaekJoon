import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static void makePibonacci(int first, int second, int cnt) {
        if(cnt == 45) return;

        pibo[cnt] = pibo[first] + pibo[second];
        makePibonacci(second, cnt, cnt + 1);
    }

    static int[] pibo = new int[45];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//        StringTokenizer st = new StringTokenizer(br.readLine());
        pibo[0] = 0;
        pibo[1] = 1;
        makePibonacci(0, 1, 2);

        int repeat = Integer.parseInt(br.readLine());
        for(int i=0;i<repeat;i++) {
            List<Integer> list = new ArrayList<>();
            int input = Integer.parseInt(br.readLine());


            for(int j=44;j>0;j--) {
                if(input == 0) break;

                if(input >= pibo[j]) {
                    list.add(pibo[j]);
                    input -= pibo[j];
                }
            }
            Collections.reverse(list);
            //출력
            for(int j=0;j<list.size();j++) {
                if(j == list.size() - 1) {
                    System.out.print(list.get(j) + "\n");
                }else {
                    System.out.print(list.get(j) + " ");
                }
            }
        }

        br.close();
    }
}
