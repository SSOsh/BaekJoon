import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class 백준11725 {
    static int[] parents;
    static boolean[] visit;
    static List<Integer>[] list;
    static int n;

    static void dfs(int v) {
        visit[v] = true;

        for (int i : list[v]) {
            if (!visit[i]) {
                parents[i] = v;
                dfs(i);
            }
        }
    }

    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try {
            n = Integer.parseInt(br.readLine());
            list = new ArrayList[n + 1];
            parents = new int[n + 1];
            visit = new boolean[n + 1];
            for (int i = 1; i <= n; i++) {
                list[i] = new ArrayList<Integer>();
            }
            int a, b;
            for (int i = 0; i < n - 1; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                a = Integer.parseInt(st.nextToken());
                b = Integer.parseInt(st.nextToken());
                list[a].add(b);
                list[b].add(a);

            }
            dfs(1);

            StringBuilder sb = new StringBuilder();
            for (int i = 2; i <= n; i++) {
                sb.append(parents[i]);
                sb.append("\n");
            }
            System.out.println(sb.toString());
        } catch (IOException e) {
            e.printStackTrace();
        }

    }
}
