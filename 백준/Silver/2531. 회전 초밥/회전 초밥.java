import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static int n, d, k, c;
    static int[] arr = new int[30001];

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        d = sc.nextInt();
        k = sc.nextInt();
        c = sc.nextInt();
        for(int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        int s = 0, e = 0;
        int kind = 0;
        int[] cnt = new int[30001]; 
        for(int i = 0; i < k; i++) {
            if(arr[i] != c) {
                cnt[arr[i]]++;
                if(cnt[arr[i]] == 1) kind++;
            }
            e++;
        }
        int res = kind;
        for(int i = 0; i < n; i++) {
            if(arr[e] != c) {
                cnt[arr[e]]++;
                if(cnt[arr[e]] == 1) kind++;
            }
            if(arr[s] != c) {
                cnt[arr[s]]--;
                if(cnt[arr[s]] == 0) kind--;
            }
            e = (e + 1) % n;
            s = (s + 1) % n;
            res = Math.max(res, kind);
        }
        System.out.println(res + 1);
    }
}
