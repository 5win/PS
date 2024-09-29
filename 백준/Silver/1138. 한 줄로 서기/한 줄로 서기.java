import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] arr = new int[11];
        for(int i = 0; i < n; i++) {
            arr[i] = sc.nextInt(); 
        }

        Stack<Integer> st1 = new Stack<>();
        Stack<Integer> st2 = new Stack<>();
        for(int i = n - 1; i >= 0; i--) {
            int idx = n - 1 - i;
            int cnt = idx - arr[i];

            while(cnt-- > 0) {
                st2.push(st1.peek());
                st1.pop();
            } 
            st1.push(i + 1);
            while(!st2.isEmpty()) {
                st1.push(st2.peek());
                st2.pop();
            }
        }

        List<Integer> res = new ArrayList<>();
        while(!st1.isEmpty()) {
            res.add(st1.peek());
            st1.pop();
        }

        Collections.reverse(res);
        for(int i : res)
            System.out.print(i + " ");
    }
}
