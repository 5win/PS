import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {
    static class Pair implements Comparable<Pair> {
        int x, y;
        public Pair(int a, int b) {
            x = a;
            y = b;
        }
        public int compareTo(Pair p) {
            return y - p.y;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        List<Pair> arr = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");
            int x = Integer.parseInt(input[0]);
            int y = Integer.parseInt(input[1]);
            arr.add(new Pair(x, y));
        }

        int cnt = 0;
        Stack<Integer> st = new Stack<>();
        for(int i = 0; i < n; i++) {
            int y = arr.get(i).y;

            if(st.isEmpty() || st.peek() < y) {
                if(y != 0)
                    st.add(y);
                continue;
            }
            if(!st.isEmpty() && st.peek() == y) continue;
            while(!st.isEmpty()) {
                if(st.peek() > y) {
                    cnt++;
                    st.pop();
                } else if(st.peek() == y) {
                    st.pop();
                } else {
                    break;
                }
            }
            if(y == 0) continue;
            st.add(y);
        }
        while(!st.isEmpty()) {
            cnt++;
            st.pop();
        }

        bw.write(String.valueOf(cnt));


        bw.flush();
        bw.close();
    }
}
