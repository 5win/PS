import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static boolean cntOne(int[] origin, int[] target) {
        int one = 0;
        int dist = 0;
        for(int i = 0; i < 26; i++) {
            int gap = Math.abs(origin[i] - target[i]);
            if(gap == 1)
                one++;
            dist += gap;
        }

        if(one <= 2 && one == dist) return true;
        return false;
    }
    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        String str = br.readLine();

        int[] originCnt = new int[26];
        for(char c : str.toCharArray()) {
            originCnt[c - 'A']++;
        }

        int res = 0;
        for(int i = 1; i < n; i++) {
            String s = br.readLine();
            int[] cnt = new int[26];
            for(char c : s.toCharArray()) {
                cnt[c - 'A']++;
            }
            boolean isSimil = cntOne(originCnt, cnt);
            if(isSimil && Math.abs(str.length() - s.length()) == 1)
                res++;
            else if(isSimil && str.length() == s.length())
                res++;
        }

        bw.write(String.valueOf(res));
        bw.flush();
        bw.close();
    }
}
