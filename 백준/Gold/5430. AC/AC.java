import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static final int INF = 1987654321;

    public static void main(String[] args) throws Exception {

        // Scanner sc = new Scanner(System.in);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        Deque<Integer> dq = new ArrayDeque<>();

        // int t = sc.nextInt();
        int t = Integer.parseInt(br.readLine());
        while(t-- > 0) {
            // String p = sc.next();
            // int n = sc.nextInt();
            // String x = sc.next();
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
                System.out.println("error");
            } else if(dq.isEmpty()) {
                System.out.println("[]");   
            } else if(isReverse) {
                System.out.print("[");
                while(dq.size() != 1) {
                    System.out.print(dq.pollLast());
                    System.out.print(",");
                }
                System.out.println(dq.pollLast() + "]");
            } else {
                System.out.print("[");
                while(dq.size() != 1) {
                    System.out.print(dq.pollFirst());
                    System.out.print(",");
                }
                System.out.println(dq.pollFirst() + "]");
            }
        }

    }
}
