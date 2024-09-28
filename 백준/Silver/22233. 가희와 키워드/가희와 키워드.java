import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static int n, m;
    static Map<String, Boolean> map = new HashMap<>();

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        n = Integer.parseInt(input[0]);
        m = Integer.parseInt(input[1]);

        for(int i = 0; i < n; i++) {
            String keyword = br.readLine();
            map.put(keyword, true);
        }

        for(int i = 0; i < m; i++) {
            input = br.readLine().split(",");
            for(int j = 0; j < input.length; j++) {
                if(map.containsKey(input[j])) {
                    map.remove(input[j]);
                }
            }
            bw.write(String.valueOf(map.size()) + "\n");
        }

        bw.flush();
        bw.close();
    }
}
