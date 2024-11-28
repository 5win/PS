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

        public int compareTo(Pair o) {
            return o.sec - sec;
        }
    }

    static int n;
    static List<Pair> arr = new ArrayList<>();

    static int solve() {
        PriorityQueue<Pair> pq = new PriorityQueue<>();

        int ret = 0;
        int idx = n - 1;
        for(int day = n; day > 0; day--) {
            for(; idx >= 0; idx--) {
                Pair here = arr.get(idx);
                if(here.fir != day) break;
                pq.offer(here);
            }

            if(!pq.isEmpty()) {
                ret += pq.poll().sec;
            }
        }
        return ret;
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        for(int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");
            int deadline = Integer.parseInt(input[0]);
            int cup = Integer.parseInt(input[1]);
            arr.add(new Pair(deadline, cup));
        }

        Collections.sort(arr, (Pair a, Pair b) -> a.fir - b.fir);

        bw.write(solve() + "\n");

        bw.flush();
        bw.close();
    }
}
