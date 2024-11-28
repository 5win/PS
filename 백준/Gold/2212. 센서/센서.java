import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static int n, k;
    static List<Integer> arr = new ArrayList<>();

    static int solve() {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

        for(int i = 0; i < arr.size() - 1; i++) {
            int dist = arr.get(i + 1) - arr.get(i);
            pq.offer(dist);
        }

        for(int i = 0; i < k - 1; i++) {
            if(!pq.isEmpty()) {
                pq.poll();
            }
        }
        
        int ret = 0;
        while(!pq.isEmpty()) {
            ret += pq.poll();
        }
        return ret;
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        k = Integer.parseInt(br.readLine());
        String[] input = br.readLine().split(" ");
        for(int i = 0; i < input.length; i++) {
            arr.add(Integer.parseInt(input[i]));
        }
        arr.stream().distinct();
        Collections.sort(arr);

        bw.write(solve() + "\n");

        bw.flush();
        bw.close();
    }
}
