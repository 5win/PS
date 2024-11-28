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

    static int n, l;
    static List<Pair> hole = new ArrayList<>();

    static int solve() {

        int ret = 0;
        int prev = 0;
        for(Pair h : hole) {
            int bridgeEnd = Math.max(h.fir, prev);
            while(bridgeEnd < h.sec) {
                bridgeEnd += l;
                ret++;
            }
            prev = bridgeEnd;
        }

        return ret;
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        n = Integer.parseInt(input[0]);
        l = Integer.parseInt(input[1]);

        for(int i = 0; i < n; i++) {
            input = br.readLine().split(" ");
            int st = Integer.parseInt(input[0]);
            int en = Integer.parseInt(input[1]);
            hole.add(new Pair(st, en));
        }
        Collections.sort(hole, (a, b) -> a.fir - b.fir);

        bw.write(solve() + "\n");

        bw.flush();
        bw.close();
    }
}
