import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static int n;
    static int[] arr = new int[2001];    

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        Arrays.fill(arr, Integer.MAX_VALUE);

        n = Integer.parseInt(br.readLine());
        String[] input = br.readLine().split(" ");
        for(int i = 0; i < n; i++) {
            int tmp = Integer.parseInt(input[i]);
            arr[i] = tmp;
        }

        Arrays.sort(arr);

        int cnt = 0;
        for(int i = 0; i < n; i++) {
            int s = 0, e = n - 1;
            while(s < e) {
                int sum = arr[s] + arr[e];
                if(s == i) {
                    s++;
                } else if(e == i) {
                    e--;
                }
                else if(sum < arr[i]) {
                    s++;
                }
                else if(arr[i] < sum) {
                    e--;
                }
                else {
                    cnt++;
                    break;
                }
            }
        }

        bw.write(String.valueOf(cnt));

        bw.flush();
        bw.close();
    }
}
