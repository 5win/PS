import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.io.*;

public class Main {

    static int[] alpha = new int[30];

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);

        String s = sc.nextLine();
        s.chars().forEach(c -> {
            if('A' <= c && c <= 'Z') {
                alpha[c - 'A']++;
            } else {
                alpha[c - 'a']++;
            }
        });

        int maxCnt = Arrays.stream(alpha).max().getAsInt();
        int cnt = (int)Arrays.stream(alpha).filter(n -> n == maxCnt).count();
        if(cnt > 1) {
            System.out.println("?");
        } else {
            for(int i = 0; i <= 26; i++) {
                if(alpha[i] == maxCnt) {
                    System.out.println((char)('A' + i));
                    break;
                }
            }
        }
    }
}
