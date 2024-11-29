import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static int n;
    static String[] str;

    static String solve() {
        PriorityQueue<String> pq = new PriorityQueue<>((String a, String b) -> {
            if(a.length() <= b.length() && b.startsWith(a))
                return 1;
            else if(a.length() > b.length() && a.startsWith(b))
                return -1;
            return a.compareTo(b);
        });

        StringBuilder sb = new StringBuilder();

        for(int i = 0; i < n; i++) {
            pq.offer(str[i]);
        }

        while(!pq.isEmpty()) {
            String here = pq.poll();
            sb.append(here.charAt(0));

            String next = here.substring(1);
            if(next.isBlank()) continue;
            pq.offer(next);
        }

        return sb.toString();
    }
    
    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        str = new String[n];

        for(int i = 0; i < n; i++) {
            str[i] = br.readLine();
        }

        bw.write(solve() + "\n");

        bw.flush();
        bw.close();
    }
}
