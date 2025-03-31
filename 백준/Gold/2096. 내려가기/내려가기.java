import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static final int INF = 1987654321;

    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int[][] arr = new int[n][3];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 3; j++) {
                arr[i][j] = sc.nextInt();
            }
        }

        int[][] maxDp = new int[n][3];
        maxDp[0][0] = arr[0][0];
        maxDp[0][1] = arr[0][1];
        maxDp[0][2] = arr[0][2];

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < 3; j++) {
                maxDp[i][j] = maxDp[i - 1][j];
                if(j - 1 >= 0) {
                    maxDp[i][j] = Math.max(maxDp[i][j], maxDp[i - 1][j - 1]);
                }
                if(j + 1 < 3) {
                    maxDp[i][j] = Math.max(maxDp[i][j], maxDp[i - 1][j + 1]);
                }
                maxDp[i][j] += arr[i][j];
            }
        }

        // min
        int[][] minDp = new int[n][3];
        minDp[0][0] = arr[0][0];
        minDp[0][1] = arr[0][1];
        minDp[0][2] = arr[0][2];

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < 3; j++) {
                minDp[i][j] = minDp[i - 1][j];
                if(j - 1 >= 0) {
                    minDp[i][j] = Math.min(minDp[i][j], minDp[i - 1][j - 1]);
                }
                if(j + 1 < 3) {
                    minDp[i][j] = Math.min(minDp[i][j], minDp[i - 1][j + 1]);
                }
                minDp[i][j] += arr[i][j];
            }
        }

        // print
        System.out.print(Math.max(maxDp[n - 1][0], Math.max(maxDp[n - 1][1], maxDp[n - 1][2])) + " ");
        System.out.println(Math.min(minDp[n - 1][0], Math.min(minDp[n - 1][1], minDp[n - 1][2])));
    }
}
