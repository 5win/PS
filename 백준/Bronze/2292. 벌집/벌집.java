import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.io.*;

public class Main {


    public static void main(String[] args) throws IOException {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int num = 1, cnt = 0;
        while(true) {
            if(n <= num) break;
            cnt++;
            num += (6 * cnt);
        }
        System.out.println(cnt + 1);
    }
}
