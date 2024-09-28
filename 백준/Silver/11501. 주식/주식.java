import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T, n;
        T = Integer.parseInt(br.readLine());
        
        while(T-- > 0) {
            n = Integer.parseInt(br.readLine());
            String[] input = br.readLine().split(" ");

            int[] arr = new int[n + 1];
            for(int i = 0; i < n; i++)
                arr[i] = Integer.parseInt(input[i]);

            int[] maxNum = new int[n + 1];
            for(int i = n - 1; i >= 0; i--)
                maxNum[i] = Math.max(maxNum[i + 1], arr[i]);

            long res = 0;
            for(int i = 0; i < n; i++) {
                if(arr[i] < maxNum[i]) {
                    res += (long)maxNum[i] - arr[i];
                }
            }
            bw.write(String.valueOf(res) + "\n");
        }


        bw.flush();
        bw.close();
    }
}
