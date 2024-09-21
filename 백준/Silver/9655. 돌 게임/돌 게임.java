import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {


    public static void main(String[] args) throws IOException {

        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        boolean[] isSk = new boolean[1001];

        isSk[1] = true;
        isSk[2] = false;
        isSk[3] = true;
        for(int i = 4; i <= n; i++) {
            isSk[i] = isSk[i - 1] == false || isSk[i - 3] == false;
        }
        if(isSk[n]) {
            System.out.println("SK");
        } else {
            System.out.println("CY");
        }
    }
}
