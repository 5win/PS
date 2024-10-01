import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();
        while(T-- > 0) {
            String str = sc.next();
            int k = sc.nextInt();
            int len = str.length();

            List<Integer>[] idx = new List[26];
            for(int i = 0; i < 26; i++)
                idx[i] = new ArrayList<>();

            for(int i = 0; i < len; i++) {
                char here = str.charAt(i);
                idx[here - 'a'].add(i);
            }

            int min = Integer.MAX_VALUE; 
            int max = 0;
            for(int i = 0; i < 26; i++) {
                for(int j = 0; j < idx[i].size() - k + 1; j++) {
                    min = Math.min(min, idx[i].get(j + k - 1) - idx[i].get(j) + 1);
                    max = Math.max(max, idx[i].get(j + k - 1) - idx[i].get(j) + 1);
                }
            }
            if(min == Integer.MAX_VALUE) {
                System.out.println(-1);
            } else {
                System.out.println(min + " " + max);
            }
        }
    }
}
