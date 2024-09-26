import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static int n, m;
    static int[] x = new int[100001];


    static boolean decision(int h) {
        if(x[0] - h > 0) return false;
        if(x[m - 1] + h < n) return false;
        for(int i = 1; i < m; i++) {
            if(x[i - 1] + h < x[i] - h)
                return false;
        }
        return true;
    }

    static int binarySearch() {
        int s = 0, e = 100000;

        while(s + 1 < e) {
            int mid = (s + e) / 2;
            if(decision(mid)) {
                e = mid;
            } else {
                s = mid;
            }
        }
        return e;
    }
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in); 

        n = sc.nextInt();
        m = sc.nextInt();
        for(int i = 0; i < m; i++) {
            x[i] = sc.nextInt();
        }
        System.out.println(binarySearch());
    }
}
