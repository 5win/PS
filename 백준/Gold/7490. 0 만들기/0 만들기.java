import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static int n;
    static List<Character> op = new ArrayList<>();
    static List<String> res = new ArrayList<>();

    static void calc(String s) {
        String str = s.replaceAll(" ", "");
        String[] exp = str.split("[+,-]");

        Iterator<Integer> iter = Arrays.stream(exp).map(Integer::parseInt).collect(Collectors.toList()).iterator();


        int sum = iter.next();
        for(int i = 0; i < str.length(); i++) {
            if(str.charAt(i) == '+') {
                sum += iter.next();
            } else if(str.charAt(i) == '-') {
                sum -= iter.next();
            }
        }
        if(sum == 0) {
            res.add(s);
        }
    }

    static void dfs(int len, String str) {
        if(len == n + 1) {
            calc(str);
            return;
        }

        dfs(len + 1, str + "+" + len);
        dfs(len + 1, str + "-" + len);
        dfs(len + 1, str + " " + len);
    }


    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        while(T-- > 0) {
            op.clear();
            res.clear();
            n = Integer.parseInt(br.readLine());

            dfs(2, "1");

            Collections.sort(res);
            for(String s : res)
                bw.write(s + "\n");
            bw.write("\n");
        }

        bw.flush();
        bw.close();
    }
}
