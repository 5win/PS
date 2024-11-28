import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static class Box implements Comparable<Box> {
        int fir, sec, third;

        public Box(int a, int b, int c) {
            fir = a;
            sec = b;
            third = c;
        }

        public int compareTo(Box o) {
            if(sec == o.sec) return o.fir - fir;
            return sec - o.sec;
        }
    }

    static int n, c, m;
    static List<Box> arr = new ArrayList<>();

    static int solve() {
        int[] sum = new int[n + 1];

        int ret = 0;
        for(Box i : arr) {
            int max = 0;
            for(int j = i.fir; j < i.sec; j++) {
                max = Math.max(max, sum[j]);
            }

            int amount = Math.min(i.third, c - max);
            ret += amount;
            for(int j = i.fir; j < i.sec; j++) {
                sum[j] += amount;
            }
        }

        return ret;
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        n = Integer.parseInt(input[0]);
        c = Integer.parseInt(input[1]);
        m = Integer.parseInt(br.readLine());

        int src, dst, weight;
        for(int i = 0; i < m; i++) {
            input = br.readLine().split(" ");
            src = Integer.parseInt(input[0]);
            dst = Integer.parseInt(input[1]);
            weight = Integer.parseInt(input[2]);
            arr.add(new Box(src, dst, weight));
        }
        Collections.sort(arr);

        bw.write(solve() + "\n");        

        bw.flush();
        bw.close();
    }
}
