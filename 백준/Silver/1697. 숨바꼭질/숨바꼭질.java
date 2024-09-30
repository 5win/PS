import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static int n, k;
    static int[] arr = new int[100001];

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        k = sc.nextInt();

        Queue<Integer> q = new LinkedList<>();
        q.offer(n);
        arr[n] = 1;
        while(!q.isEmpty()) {
            int here = q.peek();
            q.poll();

            if(here != 0 && arr[here - 1] == 0) {
                arr[here - 1] = arr[here] + 1;
                q.offer(here - 1);
            }
            if(here < 100000 && arr[here + 1] == 0) {
                arr[here + 1] = arr[here] + 1;
                q.offer(here + 1);
            }
            if(here * 2 <= 100000 && arr[here * 2] == 0) {
                arr[here * 2] = arr[here] + 1;
                q.offer(here * 2);
            }
        }
        System.out.println(arr[k] - 1);
    }
}
