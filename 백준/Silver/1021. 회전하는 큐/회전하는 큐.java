import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static final int INF = 1987654321;
    static int n, m;
    static int[] arr;

    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        m = sc.nextInt();

        arr = new int[m];
        for(int i = 0; i < m; i++) {
            arr[i] = sc.nextInt();
        }

        Deque<Integer> dq = new ArrayDeque<>();
        for(int i = 1; i <= n; i++) {
            dq.offerLast(i);
        }

        int res = 0;
        for(int i = 0; i < m; i++) {
            int cur = arr[i];

            int cnt = 0;
            while(dq.peekFirst() != cur) {
                dq.offerLast(dq.pollFirst());
                cnt++;
            }
            
            if(cnt <= dq.size() / 2) {  // 왼쪽 이동이 더 짧으면
                res += cnt;
            } else {
                res += dq.size() - cnt;
            }
            dq.pollFirst();
        }

        System.out.println(res);
    }
}
