import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static class Pair implements Comparable<Pair> {
        int fir, sec;
        public Pair(int a, int b) {
            fir = a;
            sec = b;
        }
        public int compareTo(Pair o) {
            if(fir == o.fir) return sec - o.sec;
            return fir - o.fir;
        }
    }

    static int n, m, a, b;
    static int[][] board;

    static boolean inRange(int y, int x) {
        return 0 <= y && y < n && 0 <= x && x < m;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        n = Integer.parseInt(input[0]);
        m = Integer.parseInt(input[1]);
        a = Integer.parseInt(input[2]);
        b = Integer.parseInt(input[3]);

        board = new int[n][m];

        List<Pair> list = new ArrayList<>();
        list.add(new Pair(0, 0));

        for(int i = 0; i < a; i++) {
            input = br.readLine().split(" ");
            int y = Integer.parseInt(input[0]);
            int x = Integer.parseInt(input[1]);
            y--; x--;
            board[y][x] = 1;
            list.add(new Pair(y, x));
        }
        list.add(new Pair(n - 1, m - 1));

        for(int i = 0; i < b; i++) {
            input = br.readLine().split(" ");
            int y = Integer.parseInt(input[0]);
            int x = Integer.parseInt(input[1]);
            y--; x--;
            board[y][x] = 2;
        }

        Collections.sort(list);

        // dp
        int[][] dp = new int[n][m];
        dp[0][0] = 1;
        for(int i = 0; i < a + 1; i++) {
            int y1 = list.get(i).fir;
            int x1 = list.get(i).sec;
            int y2 = list.get(i + 1).fir;
            int x2 = list.get(i + 1).sec;

            if(y1 != 0 || x1 != 0) dp[y1][x1] = 0;

            for(int r = y1; r <= y2; r++) {
                for(int c = x1; c <= x2; c++) {
                    if(board[r][c] == 2) continue;
                    if(inRange(r - 1, c) && board[r - 1][c] != 2) {
                        dp[r][c] += dp[r - 1][c];
                    }
                    if(inRange(r, c - 1) && board[r][c - 1] != 2) {
                        dp[r][c] += dp[r][c - 1];
                    }
                }
            }
        }
        bw.write(dp[n - 1][m - 1] + "\n");


        bw.flush();
        bw.close();
    }
}
