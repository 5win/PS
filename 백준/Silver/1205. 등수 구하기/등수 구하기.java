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
        int score = Integer.parseInt(input[1]);
        int p = Integer.parseInt(input[2]);

        if(n > 0)
            input = br.readLine().split(" ");
        int[] arr = new int[n + 1];
        for(int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(input[i]);
        }

        int bigCnt = 1;
        int idx = 1;
        for(int i = 0; i < n; i++) {
            if(arr[i] > score) bigCnt++;
            if(arr[i] >= score) idx++;
        }

        if(idx > p)
            bw.write("-1\n");
        else
            bw.write(String.valueOf(bigCnt));

        bw.flush();
        bw.close();
    }
}
