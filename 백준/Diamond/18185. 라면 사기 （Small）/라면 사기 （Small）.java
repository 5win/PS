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
        // int[] arr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        String[] input = br.readLine().split(" ");
        int[] arr = new int[n + 2];
        for(int i = 0; i < n; i++)
            arr[i] = Integer.parseInt(input[i]);

        int cost = 0;
        for(int i = 0; i < n; i++) {
            // 가능한한 두 번째 방법으로 구매
            while(arr[i] > 0 && arr[i + 1] > 0 && arr[i + 1] > arr[i + 2]) {
                arr[i]--;
                arr[i + 1]--;
                cost += 5;
            }

            // 현재 가능한 모든 3번째 방법을 구매
            int min = Math.min(arr[i], Math.min(arr[i + 1], arr[i + 2]));
            cost += min * 7;
            arr[i] -= min;
            arr[i + 1] -= min;
            arr[i + 2] -= min;

            // i번째만 남은 부분을 모두 3원에 구매
            cost += arr[i] * 3;
            arr[i] = 0;
        }

        bw.write(cost + "\n");

        bw.flush();
        bw.close();
    }
}
