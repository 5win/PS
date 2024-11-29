import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static int t;
    static String str;

    static boolean check(int l, int mid, int r) {
        int left = mid - 1, right = mid + 1;
        while(l <= left && right < r) {
            if(str.charAt(left) == str.charAt(right)) return false;
            left--;
            right++;
        }
        return true;
    }

    static boolean solve(int l, int r) {

        if(l >= r) return true;

        int mid = (l + r) / 2;
        if(!check(l, mid, r)) return false;

        boolean ret = true;
        ret = ret && solve(l, mid - 1) && solve(mid + 1, r);
        return ret;
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        t = Integer.parseInt(br.readLine());
        while(t-- > 0) {
            str = br.readLine();
            if(solve(0, str.length()))
                bw.write("YES\n");
            else
                bw.write("NO\n");
        }

        bw.flush();
        bw.close();
    }
}
