import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        String[] input = br.readLine().split(" ");

        int[] nums = new int[100001];
        for(int i = 0; i < n; i++) nums[i] = Integer.parseInt(input[i]);

        int[] cnt = new int[100001];
        long res = 0;
        int s = 0, e = 0;
        while(s < n) {
            while(e < n) {
                if(cnt[nums[e]] > 0) break;
                cnt[nums[e]]++;
                e++;
            }
            res += e - s;
            cnt[nums[s]]--;
            s++;
        }
        bw.write(String.valueOf(res));

        bw.flush();
        bw.close();
    }
}
