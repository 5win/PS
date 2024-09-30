import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        String str = sc.nextLine();

        char[] arr = str.toCharArray();

        int totalA = (int) str.chars().filter(c -> c == 'a').count();
        int res = 1987654321;
        
        for(int i = 0; i < arr.length; i++) {
            int cnt = 0;
            for(int j = 0; j < totalA; j++) {
                if(arr[(i + j) % arr.length] == 'b') cnt++;
            }
            res = Math.min(res, cnt);
        }
        System.out.println(res);
    }
}
