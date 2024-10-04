import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static class Pair implements Comparable<Pair> {
        int fir, sec;
        public Pair(int a, int b) {
            fir = a;
            sec = b;
        }
        public int compareTo(Pair p) {
            if(p.sec == sec) return fir - p.fir;
            return p.sec - sec;
        }
    }

    static int n, k;
    static int[][] jewrly;
    static int[] w;


    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        n = Integer.parseInt(input[0]);
        k = Integer.parseInt(input[1]);

        jewrly = new int[n][2];
        w = new int[k];

        for(int i = 0; i < n; i++) {
            input = br.readLine().split(" ");
            jewrly[i][0] = Integer.parseInt(input[0]);
            jewrly[i][1] = Integer.parseInt(input[1]);
        }
        int maxW = 0;
        for(int i = 0; i < k; i++) {
            w[i] = Integer.parseInt(br.readLine());
            maxW = Math.max(maxW, w[i]);
        }

        PriorityQueue<Pair> pq = new PriorityQueue<>();
        Arrays.sort(jewrly, (p1, p2) -> p1[0] - p2[0]);
        Arrays.sort(w);

        long sum = 0;
        int jIdx = 0;
        for(int i = 0; i < k; i++) {
            while(jIdx < n && jewrly[jIdx][0] <= w[i])  {
                pq.offer(new Pair(jewrly[jIdx][0], jewrly[jIdx][1]));
                jIdx++;
            }
            if(!pq.isEmpty()) {
                sum += pq.peek().sec;
                pq.poll();
            }
        }
        
        bw.write(String.valueOf(sum));

        bw.flush();
        bw.close();
    }
}
