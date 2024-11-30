import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static int n;
    static List<Integer> arr = new ArrayList<>();

    static int solve() {
        int ret1 = 0, ret2 = 0;
        int evenCnt = 0, oddCnt = 0;
        for(int i = 0; i < n; i++) {
            if(arr.get(i) % 2 != 0) {
                // left odd, right even
                ret1 += evenCnt;

                oddCnt++; // odd Cnt
            } else {
                evenCnt++; // even Cnt
                
                ret2 += oddCnt;
            }
        }
        return Math.min(ret1, ret2);
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());

        String[] input = br.readLine().split(" ");
        for(int i = 0; i < n; i++) {
            int num = Integer.parseInt(input[i]);
            arr.add(num);
        }

        bw.write(solve() + "\n");

        bw.flush();
        bw.close();
    }
}
