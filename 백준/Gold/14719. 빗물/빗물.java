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
        int h = Integer.parseInt(input[0]);
        int w = Integer.parseInt(input[1]);
        input = br.readLine().split(" ");

        int[] arr = new int[501];
        for(int i = 0; i < w; i++) 
            arr[i] = Integer.parseInt(input[i]);
        
        int sum = 0;
        for(int i = 0; i < w; i++) {
            int left = 0;
            for(int j = i - 1; j >= 0; j--) {
                left = Math.max(left, arr[j]);
            }
            int right = 0;
            for(int j = i + 1; j < w; j++) {
                right = Math.max(right, arr[j]);
            }
            int minH = Math.min(left, right);
            if(minH > arr[i])
                sum += minH - arr[i];
        }
        bw.write(String.valueOf(sum));

        bw.flush();
        bw.close();
    }
}
