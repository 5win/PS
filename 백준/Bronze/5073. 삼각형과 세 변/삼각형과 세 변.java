import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.io.*;

public class Main {

    static int[] len = new int[3];

    public static void main(String[] args) throws IOException {

        Scanner sc = new Scanner(System.in);
        while(true) {
            for(int i = 0; i < 3; i++) {
                len[i] = sc.nextInt();
            }
            Arrays.sort(len);
            if(len[0] == 0 && len[2] == 0) break;

            if (len[0] + len[1] <= len[2]) {
                System.out.println("Invalid");
            } else if (len[0] == len[2]) {
                System.out.println("Equilateral");
            } else if (len[0] == len[1] || len[1] == len[2]) {
                System.out.println("Isosceles");
            } else {
                System.out.println("Scalene");
            }
        }
    }
}
