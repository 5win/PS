import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static int n;
    static List<Size> arr = new ArrayList<>();

    static class Size {
        int x, y;

        public Size(int y, int x) {
            this.y = y;
            this.x = x;
        }

        public int comp(Size s) {
            if(this.x < s.x && this.y < s.y) return -1;
            else if(this.x > s.x && this.y > s.y) return 1;
            return 0;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        for(int i = 0; i < n; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();

            arr.add(new Size(x, y));
        }

        int[] res = new int[n];
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            Size cur = arr.get(i);
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                if(cur.comp(arr.get(j)) < 0) cnt++;
            }
            res[i] = cnt;
        }

        for(int i : res) {
            System.out.print(i + 1 + " ");
        }
    }
}
