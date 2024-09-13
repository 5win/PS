import java.util.*;

public class Main {
    static int x;
    static PriorityQueue<Integer> pq = new PriorityQueue<>();

    static void solve() {
        pq.offer(64);
        int lenSum = 64;

        while(lenSum != x) {
            int minVal = pq.poll();
            int num = minVal / 2;

            pq.offer(num);
            if(lenSum - num >= x) {
                lenSum -= num;
                continue;
            }
            pq.offer(num);
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        x = sc.nextInt();

        solve();
        System.out.println(pq.size());
    }
}