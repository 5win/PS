import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static class Pair {
        String name;
        int upper;

        public Pair(String n, int u) {
            name = n;
            upper = u;
        }
    }

    static int n, m;
    static Pair[] arr = new Pair[100001];

    static int lowerBound(int target) {
        int s = 0, e = n;
        while(s < e) {
            int mid = (s + e) / 2;
            if(arr[mid].upper >= target) {
                e = mid;
            } else {
                s = mid + 1;
            }
        }
        return e;
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        n = Integer.parseInt(input[0]);
        m = Integer.parseInt(input[1]);


        for(int i = 0; i < n; i++) {
            input = br.readLine().split(" ");
            arr[i] = new Pair(input[0], Integer.parseInt(input[1]));
        }
        
        for(int i = 0; i < m; i++) {
            int target = Integer.parseInt(br.readLine());
            int idx = lowerBound(target);
            bw.write(arr[idx].name + "\n");
        }

        bw.flush();
        bw.close();
    }
}
