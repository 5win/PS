import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static int n, m, p;
    static int[] rank = new int[51];

    static int solve() {

        int ranking = 1;
        int idx = 0;
        for(int i = 0; i < n; i++) {
            if(rank[i] > m) ranking++;
            if(rank[i] >= m) idx++;
        }
        if(ranking > p) return -1;
        else if(idx >= p) return -1;
        return ranking;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        m = sc.nextInt();
        p = sc.nextInt();
        for(int i = 0; i < n; i++) {
            rank[i] = sc.nextInt();
        }
        System.out.println(solve());
    }
}
