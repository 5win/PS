import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);
        int l = Integer.parseInt(input[2]);
        int k = Integer.parseInt(input[3]);

        int[] starX = new int[101];
        int[] starY = new int[101];

        for(int i = 0; i < k; i++) {
            input = br.readLine().split(" ");
            int x = Integer.parseInt(input[0]);
            int y = Integer.parseInt(input[1]);
            starX[i] = x;
            starY[i] = y;
        }

        int res = 0;
        for(int i = 0; i < k; i++) {
            for(int j = 0; j < k; j++) {
                int x = Math.min(starX[i], starX[j]);
                int y = Math.min(starY[i], starY[j]);
                int cnt = 0;
                for(int t = 0; t < k; t++) {
                    if(x <= starX[t] && starX[t] <= x + l && y <= starY[t] && starY[t] <= y + l)
                        cnt++;
                }
                res = Math.max(res, cnt);
            }
        }
        bw.write(String.valueOf(k - res));

        bw.flush();
        bw.close();
    }
}
