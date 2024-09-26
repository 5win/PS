import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in); 
        Queue<Integer> q = new LinkedList<>();
        // List<Integer> q = new LinkedList<>();

        int n = sc.nextInt();
        for(int i = 1; i <= n; i++) {
            q.offer(i);
        }

        while(q.size() > 1) {
            q.poll();
            q.offer(q.peek());
            q.poll();
        }
        System.out.println(q.peek());
    }
}
