import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {
    static int[] arr = new int[100001];
    static int sum = Integer.MAX_VALUE;
    static int[] res = {0, 0};

    static void binarySearch(int s, int e, int left) {
        while(s <= e) {
            int mid = (s + e) / 2;
            int ab = Math.abs(arr[left] + arr[mid]);

            if(sum > ab) {
                sum = ab;
                res[0] = arr[left]; res[1] = arr[mid];
            }

            if(arr[mid] + arr[left] <= 0) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        String[] input = br.readLine().split(" ");
        for(int i = 0; i < n; i++) arr[i] = Integer.parseInt(input[i]);

        for(int i = 0; i < n; i++) {
            binarySearch(i + 1, n - 1, i);
        }

        bw.write(String.valueOf(res[0]) + " " + String.valueOf(res[1]));

        bw.flush();
        bw.close();
    }
}
