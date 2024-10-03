import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static int n, c;
    static int[] arr;

    static boolean decision(int x) {
        int here = arr[0];
        int cnt = 0;
        for(int i = 1; i < n; i++) {
            if(arr[i] - here >= x) {
                here = arr[i];
                cnt++;
            }
        }
        return cnt >= c - 1;
    }

    static int binarySearch() {
        int s = 1, e = (int) 1e9 + 1;
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

        String[] input = br.readLine().split(" ");
        n = Integer.parseInt(input[0]);
        c = Integer.parseInt(input[1]);
        arr = new int[n];

        for(int i = 0; i < n; i++)
            arr[i] = Integer.parseInt(br.readLine());
        Arrays.sort(arr);

        bw.write(String.valueOf(binarySearch()));

        bw.flush();
        bw.close();
    }
}
