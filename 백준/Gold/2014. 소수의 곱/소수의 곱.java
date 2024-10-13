import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static int k, n;
    static int[] prime;

    static long solve() {
        PriorityQueue<Long> pq = new PriorityQueue<>();

        for(int i : prime)
            pq.offer((long)i);
        
        long prev = -1;
        long max = prime[k - 1];
        for(int j = 0; j < n - 1; j++) {
            long min = pq.poll();

            prev = min;
            for(int i : prime) {
                long next = min * i;

                if(next >= Integer.MAX_VALUE) break;
                pq.offer(next);

                if(min % i == 0) break;
          
            }
        }
        return pq.peek();
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        k = Integer.parseInt(input[0]);
        n = Integer.parseInt(input[1]);

        prime = new int[k];

        input = br.readLine().split(" ");
        for(int i = 0; i < k; i++) {
            prime[i] = Integer.parseInt(input[i]);
        }

        long res = solve();
        bw.write(res + "\n");

        bw.flush();
        bw.close();
    }
}
