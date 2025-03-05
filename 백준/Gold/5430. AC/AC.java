import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static final int INF = 1987654321;

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        Deque<Integer> dq = new ArrayDeque<>();

        int t = Integer.parseInt(br.readLine());
        while(t-- > 0) {
            String p = br.readLine();
            int n = Integer.parseInt(br.readLine());
            String x = br.readLine();

            // split input array
            String[] nums = x.substring(1, x.length() - 1).split(",");

            // fill deque
            dq.clear();
            for(String num : nums) {
                if(num.isEmpty()) continue;
                dq.offerLast(Integer.parseInt(num));
            }

            // operation
            boolean isError = false;
            boolean isReverse = false;
            for(char op : p.toCharArray()) {
                if(op == 'R') {
                    isReverse = !isReverse;
                } else {
                    if(dq.isEmpty()) {
                        isError = true;
                        break;
                    }
                    if(isReverse) {
                        dq.pollLast();
                    } else {
                        dq.pollFirst();
                    }
                }
            }

            // print
            if(isError) {
                bw.write("error\n");
            } else if(dq.isEmpty()) { 
                bw.write("[]\n");
            } else if(isReverse) {
                bw.write("[");
                while(dq.size() != 1) {
                    bw.write(dq.pollLast() + ",");
                }
                bw.write(dq.pollLast() + "]\n");
            } else {
                bw.write("[");
                while(dq.size() != 1) {
                    bw.write(dq.pollFirst() + ",");
                }
                bw.write(dq.pollFirst() + "]\n");
            }
            bw.flush();
        }

    }
}
