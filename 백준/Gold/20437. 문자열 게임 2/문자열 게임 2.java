import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static int k;
    static String str;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        while(T-- > 0) {
            str = br.readLine();
            k = Integer.parseInt(br.readLine());

            int min = Integer.MAX_VALUE, max = 0;
            int[] cnt = new int[30];
            char[] arr = str.toCharArray();
            for(char c : arr) cnt[c - 'a']++;

            int len = str.length();
            for(int i = 0; i < len; i++) {
                if(cnt[arr[i] - 'a'] >= k) {
                    int kCnt = 0;
                    for(int j = i; j < len; j++) {
                        if(arr[i] == arr[j]) kCnt++;
                        if(kCnt == k) {
                            min = Math.min(min, j - i + 1);
                            max = Math.max(max, j - i + 1);
                            break;
                        }
                    }
                }
                cnt[arr[i] - 'a']--;
            }

            if(min == Integer.MAX_VALUE)
                bw.write("-1\n");
            else 
                bw.write(String.valueOf(min) + " " + String.valueOf(max) + "\n");

        }

        bw.flush();
        bw.close();
    }
}
