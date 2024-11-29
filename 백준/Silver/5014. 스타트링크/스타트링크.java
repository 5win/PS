import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static int f, s, g, u, d;

    static int bfs() {

        int[] visited = new int[f + 1];
        Queue<Integer> q = new LinkedList<>();

        Arrays.fill(visited, -1);
        visited[s] = 0;
        q.offer(s);

        while(!q.isEmpty()) {
            int here = q.poll();

            int next = here - d;
            if(next > 0 && visited[next] == -1) {
                visited[next] = visited[here] + 1;
                q.offer(next);
            }
            next = here + u;
            if(next <= f && visited[next] == -1) {
                visited[next] = visited[here] + 1;
                q.offer(next);
            }
        }

        return visited[g];
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        f = Integer.parseInt(input[0]);
        s = Integer.parseInt(input[1]);
        g = Integer.parseInt(input[2]);
        u = Integer.parseInt(input[3]);
        d = Integer.parseInt(input[4]);

        int ret = bfs();
        if(ret == -1) {
            bw.write("use the stairs\n");
        } else {
            bw.write(ret + "\n");
        }

        bw.flush();
        bw.close();
    }
}
