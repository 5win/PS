import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);

        int p;
        int[] arr = new int[21];

        p = sc.nextInt();
        for(int t = 1; t <= p; t++) {
            sc.nextInt();
            for(int i = 0; i < 20; i++) {
                arr[i] = sc.nextInt();
            } 

            int cnt = 0;
            for(int i = 0; i < 20; i++) {
                for(int j = i - 1; j >= 0; j--) {
                    if(arr[j] > arr[i]) cnt++;
                }
            }
            System.out.println(t + " " + cnt);
        }
    }
}
