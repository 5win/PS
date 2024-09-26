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
        int x = Integer.parseInt(input[1]);

        input = br.readLine().split(" ");
        int[] visit = new int[250001];
        for(int i = 1; i <= n; i++)
            visit[i] = Integer.parseInt(input[i - 1]);

        int[] psum = new int[250001];
        for(int i = 1; i <= n; i++)
            psum[i] = psum[i - 1] + visit[i];
        
        int maxVisit = 0, cnt = 0;
        for(int i = x; i <= n; i++) {
            int sum = psum[i] - psum[i - x];
            if(sum > maxVisit) {
                maxVisit = sum;
                cnt = 1;
            } else if(sum == maxVisit) {
                cnt++;
            }
        }

        if(maxVisit == 0) {
            bw.write("SAD");
        } else {
            bw.write(String.valueOf(maxVisit) + '\n');
            bw.write(String.valueOf(cnt));
        }

        bw.flush();
        bw.close();
    }
}
