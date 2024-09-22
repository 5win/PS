import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static int n;
    static String game;
    static Set<String> played = new HashSet<>();
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        game = sc.next();
        sc.nextLine();

        int res = 0;
        int cnt = 1;
        for(int i = 0; i < n; i++) {
            String name = sc.nextLine();

            if(played.contains(name)) continue;
            played.add(name);
            cnt++;

            if(game.equals("Y") && cnt == 2) {
                res++;
                cnt = 1;
            } else if(game.equals("F") && cnt == 3) {
                res++;
                cnt = 1;
            } else if(game.equals("O") && cnt == 4) {
                res++;
                cnt = 1;
            }
        }
        System.out.println(res);

    }
}
