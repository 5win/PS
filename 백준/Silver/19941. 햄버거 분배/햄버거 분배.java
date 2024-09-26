import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int k = Integer.parseInt(input[1]);

        String s = br.readLine();

        StringBuilder sb = new StringBuilder(s);

        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(sb.charAt(i) != 'P') continue;

            int start = Math.max(i - k, 0);
            int end = Math.min(i + k, n - 1);
            for(int j = start; j <= end; j++) {
                if(sb.charAt(j) == 'H') {
                    cnt++;
                    sb.setCharAt(j, 'X');
                    break;
                }
            }
        }
        bw.write(String.valueOf(cnt));

        bw.flush();
        bw.close();
    }
}
