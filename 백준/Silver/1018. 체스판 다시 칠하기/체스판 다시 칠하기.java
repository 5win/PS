import java.io.*;
import java.util.*;
import java.util.stream.IntStream;

public class Main {

    static int n, m;
    static String[] board = new String[51];

    static int assertChess(int y, int x) {
        int cnt1 = 0, cnt2 = 0;

        for(int i = y; i < y + 8; i++) {
            for(int j = x; j < x + 8; j++) {
                if((i + j) % 2 == 0 && board[i].charAt(j) == 'W')
                    cnt1++;
                else if((i + j) % 2 == 1 && board[i].charAt(j) == 'B')
                    cnt1++;

                if((i + j) % 2 == 0 && board[i].charAt(j) == 'B')
                    cnt2++;
                else if((i + j) % 2 == 1 && board[i].charAt(j) == 'W')
                    cnt2++;
            }
        }
        return Math.min(cnt1, cnt2);
    }

    static int solve() {
        int ret = 1987654321;
        for(int i = 0; i <= n - 8; i++) {
            for(int j = 0; j <= m - 8; j++) {
                ret = Math.min(ret, assertChess(i, j));
            }
        }
        return ret;
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        String[] input = br.readLine().split(" ");
        n = Integer.parseInt(input[0]);
        m = Integer.parseInt(input[1]);

        for(int i = 0; i < n; i++) {
            board[i] = br.readLine();
        }

        int res = solve();
        bw.write(String.valueOf(res));
        bw.newLine();
        bw.flush();
        bw.close();
    }
}