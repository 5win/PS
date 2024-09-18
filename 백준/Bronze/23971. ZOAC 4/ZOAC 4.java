import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.io.*;

public class Main { 
    static int h, w, n, m;

    public static void main(String[] args) throws IOException {

        Scanner sc = new Scanner(System.in);
        h = sc.nextInt();
        w = sc.nextInt();
        n = sc.nextInt();
        m = sc.nextInt();
        
        int cnt = 0;
        for(int i = 0; i < h; i += (n + 1)) {
            for(int j = 0; j < w; j += (m + 1)) {
                cnt++;
            }
        }

        System.out.println(cnt);
    }
}
