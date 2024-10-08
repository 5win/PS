import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {


    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int k = sc.nextInt();
        int cnt[] = new int[100001];
        int arr[] = new int[200001];

        for(int i = 0; i < n; i++)
            arr[i] = sc.nextInt();

        int res = 0;
        int s = 0, e = 0;
        while(s < n && e < n) {
            if(cnt[arr[e]] < k) {
                cnt[arr[e]]++;
                e++;
                res = Math.max(res, e - s);
            } else {
                cnt[arr[s]]--;
                s++;
            }
        }
        System.out.println(res);
    }
}
