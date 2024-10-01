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

            int[] cnt = new int[27];
            int len = str.length();

            int res1 = Integer.MAX_VALUE;

            int s = 0, e = 0;
            while(s < len && e < len) {
                char here = str.charAt(e);
                cnt[here - 'a']++;
                e++;
                if(cnt[here - 'a'] == k) {
                    while(cnt[here - 'a'] == k && s < len) {
                        cnt[str.charAt(s) - 'a']--;
                        s++;
                    }
                    res1 = Math.min(res1, e - s + 1);
                }
            }
            if(res1 == Integer.MAX_VALUE) {
                System.out.println(-1);
                continue;
            }
            else {
                System.out.print(res1 + " ");
            }

            List<Integer>[] idx = new List[26];
            for(int i = 0; i < 26; i++)
                idx[i] = new ArrayList<>();

            for(int i = 0; i < len; i++) {
                char here = str.charAt(i);
                idx[here - 'a'].add(i);
            }

            int res2 = 0;
            for(int i = 0; i < 26; i++) {
                for(int j = 0; j < idx[i].size() - k + 1; j++) {
                    res2 = Math.max(res2, idx[i].get(j + k - 1) - idx[i].get(j) + 1);
                }
            }
            System.out.println(res2); 
        }

    }
}
