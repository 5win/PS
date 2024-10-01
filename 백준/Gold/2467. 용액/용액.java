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
        int[] arr = new int[100001];
        for(int i = 0; i < n; i++) arr[i] = Integer.parseInt(input[i]);

        int s = 0, e = n - 1;
        int[] res = {arr[s], arr[e]};
        int sum = Math.abs(arr[s] + arr[e]);

        while(s < e) {
            int cur = arr[s] + arr[e];
            if(Math.abs(cur) < sum) {
                sum = Math.abs(cur);
                res[0] = arr[s]; res[1] = arr[e];
            }
            if(cur <= 0) s++;
            else e--;
        }
        bw.write(String.valueOf(res[0]) + " " + String.valueOf(res[1]));

        bw.flush();
        bw.close();
    }
}
