import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static int n, k;
    static int[] A = new int[201];
    static int[] robot = new int[201];
    static int cnt = 0;

    static void rotate() {
        int tmp = A[2 * n - 1];
        for(int i = 2 * n - 1; i > 0; i--) {
            A[i] = A[i - 1];
            robot[i] = robot[i - 1];
        }
        A[0] = tmp;
        robot[0] = 0;
    }

    static void move() {
        for(int i = n - 2; i >= 0; i--) {
            if(robot[i] != 1) continue;
            if(robot[i + 1] != 1 && A[i + 1] > 0) {
                robot[i + 1] = 1;
                robot[i] = 0;
                A[i + 1]--;
            }
        }
    }
    static void getRobot() {
        if(robot[n - 1] == 1) robot[n - 1] = 0;
    }

    static void setRobot() {
        if(A[0] > 0) {
            robot[0] = 1;
            A[0]--;
        }
    }

    static void updateK() {
        int sum = 0;
        for(int i = 0; i < 2 * n; i++) {
            if(A[i] <= 0) sum++;
        }
        cnt = sum;
    }

    static int solve() {
        int t = 0;
        while(true) {
            t++;
            rotate();
            getRobot();
            move();
            getRobot();
            setRobot();
            updateK();
            if(cnt >= k) break;
        }
        return t;
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        k = sc.nextInt();
        for(int i = 0; i < 2 * n; i++) {
            A[i] = sc.nextInt();
        }

        System.out.println(solve());
    }
}
