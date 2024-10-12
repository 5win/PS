import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static int xs,ys, xe, ye;
    static long[][] adj = new long[10][10];

    static int calcDist(int x1, int y1, int x2, int y2) {
        return Math.abs(x1 - x2) + Math.abs(y1 - y2);
    }

    static void floyd() {
        for(int k = 0; k < 8; k++) {
            for(int i = 0; i < 8; i++) {
                for(int j = 0; j < 8; j++) {
                    adj[i][j] = Math.min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        xs = Integer.parseInt(input[0]);
        ys = Integer.parseInt(input[1]);
        
        input = br.readLine().split(" ");
        xe = Integer.parseInt(input[0]);
        ye = Integer.parseInt(input[1]);

        
        for(int i = 0; i < 8; i++) {
            Arrays.fill(adj[i], Long.MAX_VALUE / 3);
            adj[i][i] = 0;
        }

        adj[0][7] = calcDist(xs, ys, xe, ye);

        int[][] teleport = new int[7][2];
        for(int i = 1; i <= 6; i += 2) {
            input = br.readLine().split(" ");
            int x1 = Integer.parseInt(input[0]);
            int y1 = Integer.parseInt(input[1]);
            int x2 = Integer.parseInt(input[2]);
            int y2 = Integer.parseInt(input[3]);
            teleport[i][0] = x1;
            teleport[i][1] = y1;
            teleport[i + 1][0] = x2;
            teleport[i + 1][1] = y2;

            adj[0][i] = calcDist(xs, ys, x1, y1);
            adj[0][i + 1] = calcDist(xs, ys, x2, y2);
            adj[i][i + 1] = 10;
            adj[i + 1][i] = 10;
            adj[i][7] = calcDist(x1, y1, xe, ye);
            adj[i + 1][7] = calcDist(x2, y2, xe, ye);
        }

        for(int i = 1; i <= 6; i++) {
            for(int j = 1; j <= 6; j++) {
                if(adj[i][j] == Long.MAX_VALUE / 3) {
                    adj[i][j] = calcDist(teleport[i][0], teleport[i][1], teleport[j][0], teleport[j][1]);
                }
            }
        }

        floyd();

        bw.write(adj[0][7] + "\n");

        bw.flush();
        bw.close();
    }
}
