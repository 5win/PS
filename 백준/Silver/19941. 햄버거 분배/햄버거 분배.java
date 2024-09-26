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

        int cnt = 0;
        boolean[] ate = new boolean[20001];
        for(int i = 0; i < s.length(); i++) {
            if(s.charAt(i) == 'H') continue;

            int start = Math.max(i - k, 0);
            int end = Math.min(i + k, s.length() - 1);
            for(int j = start; j <= end; j++) {
                if(s.charAt(j) == 'H' && !ate[j]) {
                    cnt++;
                    ate[j] = true;
                    break;
                }
            }
        }
        bw.write(String.valueOf(cnt));

        bw.flush();
        bw.close();
    }
}
