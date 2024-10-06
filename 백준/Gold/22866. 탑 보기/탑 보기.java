import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static class Pair {
        int fir, sec;
        public Pair(int a, int b) {
            fir = a;
            sec = b;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        String[] input = br.readLine().split(" ");
        int[] arr = new int[n];
        for(int i = 0; i < n; i++)
            arr[i] = Integer.parseInt(input[i]);
        
        int[] leftCnt = new int[n];
        int[] leftIdx = new int[n];
        int[] rightCnt = new int[n];
        int[] rightIdx = new int[n];

        Arrays.fill(leftIdx, -1);
        Arrays.fill(rightIdx, -1);

        Stack<Pair> st = new Stack<>();
        st.add(new Pair(arr[0], 0));
        leftCnt[0] = 0;
        for(int i = 1; i < n; i++) {
            if(!st.isEmpty() && arr[i] == st.peek().fir) {
                st.pop();
                leftCnt[i] = st.size();
                if(!st.isEmpty())
                    leftIdx[i] = st.peek().sec;
                st.add(new Pair(arr[i], i));

            } else if(!st.isEmpty() && arr[i] < st.peek().fir) {
                leftCnt[i] = st.size();
                leftIdx[i] = st.peek().sec;
                st.add(new Pair(arr[i], i));
            } else {
                while(!st.isEmpty() && st.peek().fir <= arr[i]) {
                    st.pop();
                }
                leftCnt[i] = st.size();
                if(!st.isEmpty())
                    leftIdx[i] = st.peek().sec;
                st.add(new Pair(arr[i], i));
            }
        }

        st.clear();
        st.add(new Pair(arr[n - 1], n - 1));
        rightCnt[n - 1] = 0;
        for(int i = n - 2; i >= 0; i--) {
            if(!st.isEmpty() && arr[i] == st.peek().fir) {
                st.pop();
                rightCnt[i] = st.size();
                if(!st.isEmpty())
                    rightIdx[i] = st.peek().sec;
                st.add(new Pair(arr[i], i));

            } else if(!st.isEmpty() && arr[i] < st.peek().fir) {
                rightCnt[i] = st.size();
                rightIdx[i] = st.peek().sec;
                st.add(new Pair(arr[i], i));
            } else {
                while(!st.isEmpty() && st.peek().fir <= arr[i]) {
                    st.pop();
                }
                rightCnt[i] = st.size();
                if(!st.isEmpty())
                    rightIdx[i] = st.peek().sec;
                st.add(new Pair(arr[i], i));
            }
        }


        for(int i = 0; i < n; i++) {
            int cnt = leftCnt[i] + rightCnt[i];
            if(cnt == 0) {
                bw.write(String.valueOf(cnt) + "\n");
            } else {
                bw.write(String.valueOf(cnt) + " ");
                if(leftIdx[i] == -1)
                    bw.write(rightIdx[i] + 1 + "");
                else if(rightIdx[i] == -1)
                    bw.write(leftIdx[i] + 1 + "");
                else if(i - leftIdx[i] <= rightIdx[i] - i)
                    bw.write(leftIdx[i] + 1 + "");
                else if(i - leftIdx[i] > rightIdx[i] - i)
                    bw.write(rightIdx[i] + 1 + "");
                bw.write("\n");
            }
        }

        bw.flush();
        bw.close();
    }
}
