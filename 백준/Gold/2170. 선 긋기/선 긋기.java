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

    static int n;
    static List<Pair> arr = new ArrayList<>();

    static int solve() {

        Stack<Pair> st = new Stack<>();

        int ret = 0;
        for(Pair i : arr) {
            if(i.sec == 1) {
                st.push(i);
            } else {
                Pair prev = st.pop();
                if(st.isEmpty()) {
                    ret += i.fir - prev.fir;
                }
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
            int src = Integer.parseInt(input[0]);
            int dst = Integer.parseInt(input[1]);

            arr.add(new Pair(src, 1));
            arr.add(new Pair(dst, -1));
        }
        Collections.sort(arr, (a, b) -> a.fir - b.fir);

        bw.write(solve() + "\n");

        bw.flush();
        bw.close();
    }
}
