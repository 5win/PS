import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static int n, d, k, c;
    static int[] arr = new int[30001];

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        d = sc.nextInt();
        k = sc.nextInt();
        c = sc.nextInt();
        for(int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        int maxCnt = 0;
        for(int i = 0; i < n; i++) {
            boolean[] visited = new boolean[30001];
            int cnt = 0;
            for(int j = 0; j < k; j++) {
                int num = arr[(i + j) % n];
                if(visited[num] || num == c) continue;
                visited[num] = true;
                cnt++;
            }
            maxCnt = Math.max(maxCnt, cnt);
        }
        System.out.println(maxCnt + 1);
    }
}
