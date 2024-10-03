import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static int[] arr = new int[1000001];
    static int n;
    static List<Integer> lst = new ArrayList<>();

    static int lowerBound(int s, int e, int target) {
        while(s < e) {
            int mid = (s + e) / 2;
            if(lst.get(mid) >= target)
                e = mid;
            else
                s = mid + 1;
        }
        return e;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        n  = Integer.parseInt(br.readLine());
        String[] input = br.readLine().split(" ");
        for(int i = 0; i < n; i++) arr[i] = Integer.parseInt(input[i]);

        lst.add(arr[0]);
        for(int i = 1; i < n; i++) {
            int ret = lowerBound(0, lst.size(), arr[i]);
            if(ret == lst.size()) {
                lst.add(arr[i]);
            } else {
                lst.set(ret, arr[i]);
            }
        }
        bw.write(String.valueOf(lst.size()));

        bw.flush();
        bw.close();
    }
}
