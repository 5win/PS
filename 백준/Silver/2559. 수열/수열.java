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
        int n, k;
        n = Integer.parseInt(input[0]);
        k = Integer.parseInt(input[1]);

        int[] arr = new int[n];
        input = br.readLine().split(" ");
        for(int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(input[i]);
        }

        int res = Integer.MIN_VALUE;
        for(int i = 0; i <= n - k; i++) {
            int sum = 0;
            for(int j = i; j < i + k; j++) {
                sum += arr[j];
            }
            res = Math.max(res, sum);
        }

        System.out.println(res);

        bw.flush();
        bw.close();
    }
}
