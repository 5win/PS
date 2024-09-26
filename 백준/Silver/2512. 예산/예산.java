import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static int n, m, maxCost = 0;
    static int[] cost = new int[10001];

    static boolean decision(int c) {
        int sum = 0;
        for(int i = 0; i < cost.length; i++) {
            sum += cost[i] > c ? c : cost[i];
        }
        return sum <= m;
    }

    static int binarySearch() {
        int s = 1, e = maxCost + 1;

        while(s + 1 < e) {
            int mid = (s + e) / 2;
            if(decision(mid)) {
                s = mid;
            } else {
                e = mid;
            }
        }
        return s;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        String[] input = br.readLine().split(" "); 
        for(int i = 0; i < input.length; i++) {
            int c = Integer.parseInt(input[i]);
            cost[i] = c;
            maxCost = Math.max(maxCost, c);
        }
        m = Integer.parseInt(br.readLine());

        int res = binarySearch();

        bw.write(String.valueOf(res));
        bw.flush();
        bw.close();
    }
}
