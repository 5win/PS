import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {



    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        char[] origin1 = br.readLine().toCharArray();
        char[] target = br.readLine().toCharArray();
        char[] origin2 = origin1.clone();

        int cnt = 0;
        // non-click 0
        for(int i = 1; i < n - 1; i++) {
            if(origin1[i - 1] != target[i - 1]) {
                origin1[i - 1] = origin1[i - 1] == '0' ? '1' : '0';
                origin1[i] = origin1[i] == '0' ? '1' : '0';
                origin1[i + 1] = origin1[i + 1] == '0' ? '1' : '0';
                cnt++;
            }
        }
        if(origin1[n - 2] != target[n - 2]) {
            origin1[n - 2] = origin1[n - 2] == '0' ? '1' : '0';
            origin1[n - 1] = origin1[n - 1] == '0' ? '1' : '0';
            cnt++;
        }

        // click 0
        int cnt2 = 1;
        origin2[0] = origin2[0] == '0' ? '1' : '0';
        origin2[1] = origin2[1] == '0' ? '1' : '0';
        for(int i = 1; i < n - 1; i++) {
            if(origin2[i - 1] != target[i - 1]) {
                origin2[i - 1] = origin2[i - 1] == '0' ? '1' : '0';
                origin2[i] = origin2[i] == '0' ? '1' : '0';
                origin2[i + 1] = origin2[i + 1] == '0' ? '1' : '0';
                cnt2++;
            }
        }
        if(origin2[n - 2] != target[n - 2]) {
            origin2[n - 2] = origin2[n - 2] == '0' ? '1' : '0';
            origin2[n - 1] = origin2[n - 1] == '0' ? '1' : '0';
            cnt2++;
        }

        boolean success1 = true;
        for(int i = 0; i < n; i++) {
            if(origin1[i] != target[i]) success1 = false;
        }
        boolean success2 = true;
        for(int i = 0; i < n; i++) {
            if(origin2[i] != target[i]) success2 = false;
        }
        if(success1 && success2)
            bw.write(String.valueOf(Math.min(cnt, cnt2)));
        else if(success1)
            bw.write(String.valueOf(cnt));
        else if(success2)
            bw.write(String.valueOf(cnt2));
        else 
            bw.write("-1");

        bw.flush();
        bw.close();
    }
}
