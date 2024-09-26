import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static class Pair implements Comparable<Pair> {
        int cnt;
        String str;

        public Pair(int c, String s) {
            cnt = c;
            str = s;
        }

        @Override
        public int compareTo(Pair o) {
            if(cnt == o.cnt) {
                if(str.length() == o.str.length()) {
                    return str.compareTo(o.str);
                }
                return o.str.length() - str.length();
            }
            return o.cnt - cnt;
        }
    }

    static int n, m;
    static Map<String, Pair> map = new HashMap<>();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        n = Integer.parseInt(input[0]);
        m = Integer.parseInt(input[1]);

        for(int i = 0; i < n; i++) {
            String s = br.readLine();
            if(s.length() < m) continue;
            int cnt = map.containsKey(s) ? map.get(s).cnt + 1 : 1;
            map.put(s, new Pair(cnt, s));
        }

        List<Pair> lst = map.values().stream().collect(Collectors.toList());
        Collections.sort(lst);

        for(Pair p : lst) {
            bw.write(p.str + '\n');
        }
        bw.flush();
        bw.close();
    }
}
