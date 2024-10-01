import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static class Pair {
        int fir, sec;
        public Pair(int f, int s) {
            fir = f;
            sec = s;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        String[] input = br.readLine().split(" ");

        Stack<Pair> top = new Stack<>();
        for(int i = 0; i < n; i++) {
            int tmp = Integer.parseInt(input[i]);
            while(!top.isEmpty()) {
                if(top.peek().sec >= tmp) {
                    // System.out.print(top.peek().fir + 1 + " ");
                    bw.write(String.valueOf(top.peek().fir + 1) + " ");
                    break;
                }
                top.pop();
            }
            if(top.isEmpty()) {
                // System.out.print("0 ");
                bw.write("0 ");
            }
            top.add(new Pair(i, tmp));
        }
        bw.flush();
        bw.close();
    }
}
