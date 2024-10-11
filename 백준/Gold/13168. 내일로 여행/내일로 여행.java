import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static final int INF = (int)1e9;
    static int n, r, m, k;
    static Map<String, Integer> city = new HashMap<>();
    static List<Integer> route = new ArrayList<>();
    static int[][] adj;
    static int[][] radj;
    static int len;

    static void floyd() {
        for(int l = 0; l < len; l++) {
            for(int i = 0; i < len; i++) {
                for(int j = 0; j < len; j++) {
                    adj[i][j] = Math.min(adj[i][j], adj[i][l] + adj[l][j]);
                    radj[i][j] = Math.min(radj[i][j], radj[i][l] + radj[l][j]);
                }
            }
        }
    }

    static boolean calcDist() {
        int sumA = 0, sumB = 0;
        for(int i = 0; i < route.size() - 1; i++) {
            int here = route.get(i);
            int next = route.get(i + 1);
            sumA += adj[here][next];
            sumB += radj[here][next];
        }
        sumB += r;

        if(sumA <= sumB)
            return false;
        return true;
    }
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        n = Integer.parseInt(input[0]);
        r = Integer.parseInt(input[1]);

        int num = 0;
        input = br.readLine().split(" ");
        for(int i = 0; i < n; i++) {
            if(city.containsKey(input[i])) continue;
            city.put(input[i], num++);
        }
        len = num;

        adj = new int[num][num];
        radj = new int[num][num];

        for(int i = 0; i < num; i++) {
            Arrays.fill(adj[i], INF);
            Arrays.fill(radj[i], INF);
            adj[i][i] = 0;
            radj[i][i] = 0;
        }

        m = Integer.parseInt(br.readLine());
        input = br.readLine().split(" ");
        for(int i = 0; i < m; i++) {
            int idx = city.get(input[i]);
            route.add(idx);
        }        

        r *= 2;

        k = Integer.parseInt(br.readLine());
        for(int i = 0; i < k; i++) {
            input = br.readLine().split(" ");
            String train = input[0];
            int src = city.get(input[1]);
            int dst = city.get(input[2]);
            int cost = Integer.parseInt(input[3]);
            cost *= 2;

            if(train.equals("Mugunghwa") || 
            train.equals("ITX-Cheongchun") ||
            train.equals("ITX-Saemaeul")) {
                radj[src][dst] = 0;
                radj[dst][src] = 0;
            } else if(train.equals("S-Train") || train.equals("V-Train")) {
                radj[src][dst] = Math.min(radj[src][dst], cost / 2);
                radj[dst][src] = Math.min(radj[dst][src], cost / 2);
            } else {
                radj[src][dst] = Math.min(radj[src][dst], cost);
                radj[dst][src] = Math.min(radj[dst][src], cost);
            }
            adj[src][dst] = Math.min(adj[src][dst], cost);
            adj[dst][src] = Math.min(adj[dst][src], cost);
        }

        floyd();
        boolean res = calcDist();
        if(res)
            bw.write("Yes\n");
        else 
            bw.write("No\n");

        bw.flush();
        bw.close();
    }
}
