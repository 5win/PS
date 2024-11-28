import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static int n, m, k;
    static List<Integer> arr = new ArrayList<>();

    static boolean decision(int x) {
        int cnt = 1;
        int st = 0, en = 1;

        while(en < arr.size()) {
            while(en < arr.size() && arr.get(en - 1) - arr.get(st) < x) {
                en++;
            }
            if(arr.get(en - 1) - arr.get(st) >= x) {
                cnt++;
                st = en - 1;
            }
        }
        return cnt >= m;
    }

    static int binarySearch() {
        int st = 1, en = 1000001;

        while(st + 1 < en) {
            int mid = (st + en) / 2;
            if(decision(mid)) {
                st = mid;
            } else {
                en = mid;
            }
        }
        return st;
    }

    static String solve() {
        int dist = binarySearch();

        StringBuilder sb = new StringBuilder("1");
        int idx = 0;
        int cnt = 1;
        for(int i = 1; i < arr.size(); i++) {
            if(cnt < m && arr.get(i) - arr.get(idx) >= dist) {
                sb.append('1');
                idx = i;
                cnt++;
            } else {
                sb.append('0');
            }
        }
        return sb.toString();
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        n = Integer.parseInt(input[0]);
        m = Integer.parseInt(input[1]);
        k = Integer.parseInt(input[2]);

        input = br.readLine().split(" ");
        for(int i = 0; i < k; i++) {
            arr.add(Integer.parseInt(input[i]));
        }

        bw.write(solve() + "\n");

        bw.flush();
        bw.close();
    }
}
