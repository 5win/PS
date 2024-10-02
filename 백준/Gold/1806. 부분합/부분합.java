import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {


    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n, s;
        int[] arr = new int[100001];
        String[] input = br.readLine().split(" ");
        n = Integer.parseInt(input[0]);
        s = Integer.parseInt(input[1]);
        input = br.readLine().split(" ");
        for(int i = 0; i < n; i++) arr[i] = Integer.parseInt(input[i]);

        int sum = 0;
        int res = Integer.MAX_VALUE;
        int st = 0, end = 0;
        while(st < n && end < n) {
            sum += arr[end];
            if(sum >= s) {
                while(sum >= s) {
                    sum -= arr[st];
                    st++;
                }
                res = Math.min(res, end - st + 2);
            }
            end++;
        }
        if(res == Integer.MAX_VALUE)
            bw.write("0");
        else
            bw.write(String.valueOf(res));

        bw.flush();
        bw.close();
    }
}
