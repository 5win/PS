import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static StringBuilder sb;
    static String s, t;
    static int res;

    static void dfs(String here) {

        if(here.length() == s.length()) {
            if(here.equals(s)) res = 1;
            return;
        }

        if(here.charAt(here.length() - 1) == 'A') {
            dfs(here.substring(0, here.length() - 1));
        } 
        if(here.charAt(0) == 'B') {
            StringBuilder next = new StringBuilder(here);
            dfs(next.reverse().deleteCharAt(next.length() - 1).toString());
        }
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        s = sc.nextLine();
        t = sc.nextLine();

        dfs(t);
        System.out.println(res);
    }
}
