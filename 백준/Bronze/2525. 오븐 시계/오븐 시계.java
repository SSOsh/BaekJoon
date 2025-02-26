import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] s = br.readLine().split(" ");
        int hour = Integer.parseInt(s[0]);
        int minute = Integer.parseInt(s[1]);
        int time = Integer.parseInt(br.readLine());

        if(minute + time >= 60) {
            hour += (minute + time) / 60;
            minute = (minute + time) % 60;
        }else {
            minute += time;
        }

        if(hour >= 24) hour -= 24;

        System.out.println(hour + " " + minute);

        br.close();
        bw.close();
    }


}