import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);


        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] sadari = new int[101];
        for(int i = 0; i < n; i++) {
            int src = sc.nextInt();
            int dst = sc.nextInt();
            sadari[src] = dst;
        }

        int[] snake = new int[101];
        for(int i = 0; i < m; i++) {
            int src = sc.nextInt();
            int dst = sc.nextInt();
            snake[src] = dst;
        }

        int[] dist = new int[101];
        Queue<Integer> q = new LinkedList<>();
        q.offer(1);        
        dist[1] = 1;

        while(!q.isEmpty()) {
            int here = q.peek();
            q.poll();

            for(int i = 6; i > 0; i--) {
                int next = here + i;
                if(next > 100 || dist[next] != 0) continue;
                dist[next] = dist[here] + 1;
                if(sadari[next] != 0) {
                    if(dist[sadari[next]] != 0) continue;
                    dist[sadari[next]] = dist[next];
                    q.offer(sadari[next]);
                } else if(snake[next] != 0) {
                    if(dist[snake[next]] != 0) continue;
                    dist[snake[next]] = dist[next];
                    q.offer(snake[next]);
                } else {
                    q.offer(next);
                }
            }
        }
        System.out.println(dist[100] - 1);
    }
}
