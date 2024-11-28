import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static class Pair {
        int fir, sec;

        public Pair(int a, int b) {
            fir = a;
            sec = b;
        }
    }

    static int n, l, p;
    static List<Pair> arr = new ArrayList<>();

    static int solve() {
        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> b.sec - a.sec);

        int ret = 0;
        int energy = p;
        for(int i = 0; i < n; i++) {
            Pair here = arr.get(i);

            while(energy < here.fir && !pq.isEmpty()) {
                energy += pq.poll().sec;
                ret++;
            }
            if(energy < here.fir) return -1;

            pq.offer(here);
        }

        while(energy < l && !pq.isEmpty()) {
            energy += pq.poll().sec;
            ret++;
        }
        return energy < l ? -1 : ret;
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        String[] input;
        for(int i = 0; i < n; i++) {
            input = br.readLine().split(" ");
            int a = Integer.parseInt(input[0]);
            int b = Integer.parseInt(input[1]);
            arr.add(new Pair(a, b));
        }
        input = br.readLine().split(" ");
        l = Integer.parseInt(input[0]);
        p = Integer.parseInt(input[1]);

        Collections.sort(arr, (a, b) -> a.fir - b.fir);

        bw.write(solve() + "\n");

        bw.flush();
        bw.close();
    }
}
