import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {



    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int a = Integer.parseInt(input[1]);
        int b = Integer.parseInt(input[2]);

        List<Integer> A = new ArrayList<>();
        List<Integer> B = new ArrayList<>();
        int oneCnt = 0;

        if(a + b <= n + 1) {
            while(a + b < n + 1) {
                oneCnt++;
                n--;
            }
            if(a > b) {
                for(int i = 1; i <= a; i++) A.add(i);
                for(int i = 1; i <= b - 1; i++) B.add(i);
            } else {
                for(int i = 1; i <= a - 1; i++) A.add(i);
                for(int i = 1; i <= b; i++) B.add(i);
            }

            if(!A.isEmpty()) {
                bw.write(A.get(0) + " ");
                for(int i = 0; i < oneCnt; i++) bw.write(1 + " ");
                for(int i = 1; i < A.size(); i++) bw.write(A.get(i) + " ");
                for(int i = B.size() - 1; i >= 0; i--) bw.write(B.get(i) + " ");
            } else {
                bw.write(B.get(B.size() - 1) + " ");
                for(int i = 0; i < oneCnt; i++) bw.write(1 + " ");
                for(int i = B.size() - 2; i >= 0; i--) bw.write(B.get(i) + " ");
            }
        } else {
            bw.write("-1\n");
        }


        bw.flush();
        bw.close();
    }
}
