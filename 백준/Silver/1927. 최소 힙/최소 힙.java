import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        PriorityQueue<Integer> pq = new PriorityQueue<>();

        int n = Integer.parseInt(br.readLine());
        while(n-- > 0) {
            int x = Integer.parseInt(br.readLine());

            if(x == 0) {
                if(pq.isEmpty()) {
                    bw.write("0\n");
                } else { 
                    bw.write(String.valueOf(pq.peek()) + "\n");
                    pq.poll();
                }
            } else {
                pq.offer(x);
            }
        }

        bw.flush();
        bw.close();
    }
}
