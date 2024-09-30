import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static int n, k;

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        k = sc.nextInt();

        int[] visited = new int[100001];
        Queue<Integer> q = new LinkedList<>();
        visited[n] = 1;
        q.offer(n);

        while(!q.isEmpty()) {
            int here = q.peek();
            q.poll();
        
            if(here * 2 <= 100000 && visited[here * 2] == 0) {
                visited[here * 2] = visited[here];
                q.offer(here * 2);
            }

            if(here - 1 >= 0 && visited[here - 1] == 0) {
                visited[here - 1] = visited[here] + 1;
                q.offer(here - 1);
            }
            if(here + 1 <= 100000 && visited[here + 1] == 0) {
                visited[here + 1] = visited[here] + 1;
                q.offer(here + 1);
            }
        }

        System.out.println(visited[k] - 1);
    }
}
