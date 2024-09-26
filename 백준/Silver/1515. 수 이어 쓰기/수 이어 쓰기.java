import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String s = br.readLine();

        int idx = 0;
        int num = 1;
        while(idx < s.length()) {
            String cur = String.valueOf(num);
            for(int i = 0; i < cur.length(); i++) {
                if(idx == s.length()) break;
                if(cur.charAt(i) == s.charAt(idx)) {
                    idx++;
                }
            }
            num++;
        }
        bw.write(String.valueOf(num - 1));
        bw.flush();
        bw.close();
    }
}
