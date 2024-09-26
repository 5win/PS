import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static int n;
    static int[] len = new int[100001];
    static int[] cost = new int[100001];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        for(int i = 0; i < n - 1; i++)
            len[i] = sc.nextInt();
        for(int i = 0; i < n; i++)
            cost[i] = sc.nextInt();

        int minCost = cost[0];
        long costSum = len[0] * minCost;
        for(int i = 1; i < n - 1; i++) {
            minCost = Math.min(minCost, cost[i]);
            costSum += len[i] * minCost;
        }
        System.out.println(costSum); 
    }
}
