import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static int n;
    static String str;

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        str = sc.next();

        char[] arr = str.toCharArray();
        int len = arr.length;

        int res = 1987654321;
        // left R
        int cnt = 0;
        int s = 0;
        while(s < len && arr[s] == 'R') s++;
        for(int i = s; i < arr.length; i++) {
            if(arr[i] == 'R') cnt++;
        }
        res = Math.min(res, cnt);

        // right R
        cnt = 0;
        s = arr.length - 1;
        while(s >= 0 && arr[s] == 'R') s--;
        for(int i = s; i >= 0; i--) {
            if(arr[i] == 'R') cnt++;
        }
        res = Math.min(res, cnt);

        // left B
        cnt = 0;
        s = 0;
        while(s < len && arr[s] == 'B') s++;
        for(int i = s; i < arr.length; i++) {
            if(arr[i] == 'B') cnt++;
        }
        res = Math.min(res, cnt);

        // right R
        s = arr.length - 1;
        while(s >= 0 && arr[s] == 'B') s--;
        cnt = 0;
        for(int i = s; i >= 0; i--) {
            if(arr[i] == 'B') cnt++;
        }
        res = Math.min(res, cnt);

        System.out.println(res);
    }
}
