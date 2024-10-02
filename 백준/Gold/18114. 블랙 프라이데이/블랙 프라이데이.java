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
        int c = Integer.parseInt(input[1]);
        input = br.readLine().split(" ");

        int[] arr = new int[5001];
        Arrays.fill(arr, Integer.MAX_VALUE);
        for(int i = 0; i < n; i++) arr[i] = Integer.parseInt(input[i]);

        Arrays.sort(arr);

        String res = "0";
        if(Arrays.binarySearch(arr, 0, n, c) >= 0)
            res = "1";
        for(int i = 0; i < n; i++) {
            int target = c - arr[i];
            int ret = Arrays.binarySearch(arr, i + 1, n, target);
            if(ret >= 0) res = "1";
        }
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int target = c - arr[i] - arr[j];
                int ret = Arrays.binarySearch(arr, j + 1, n, target);
                if(ret >= 0) res = "1";
            }
        }

        bw.write(res);

        bw.flush();
        bw.close();
    }
}
