import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static int n;
    static int[] status = new int[101];

    static void solve(int sex, int num) {

        if(sex == 1) {
            for(int i = 1; i <= n; i++) {
                if(i % num == 0) {
                    status[i] = (status[i] + 1) % 2;
                }
            }
        } else {
            int s = num - 1, e = num + 1;
            status[num] = (status[num] + 1) % 2;
            while(1 <= s && e <= n) {
                if(status[s] != status[e]) break;
                status[s] = (status[s] + 1) % 2;
                status[e] = (status[e] + 1) % 2;
                s--; e++;
            }
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in); 

        n = sc.nextInt();
        for(int i = 1; i <= n; i++) {
            status[i] = sc.nextInt();
        }

        int m = sc.nextInt();
        int sex, num;
        while(m-- > 0) {
            sex = sc.nextInt();
            num = sc.nextInt();
            solve(sex, num);
        }

        for(int i = 1; i <= n; i++) {
            System.out.print(status[i] + " ");
            if(i % 20 == 0) System.out.println();
        }
    }
}
