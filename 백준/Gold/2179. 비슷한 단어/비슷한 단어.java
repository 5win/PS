import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] str = new String[20001];
        int n = Integer.parseInt(br.readLine());        
        for(int i = 0; i < n; i++) 
            str[i] = br.readLine();

        int maxLen = 0;
        String[] res = new String[2];
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int len = 0;
                for(int k = 0; k < Math.min(str[i].length(), str[j].length()); k++) {
                    if(str[i].charAt(k) == str[j].charAt(k)) len++;
                    else break;
                }
                if(maxLen < len) {
                    maxLen = len;
                    res[0] = str[i]; res[1] = str[j];
                }
            }
        }
        bw.write(res[0] + "\n");
        bw.write(res[1]);

        bw.flush();
        bw.close();
    }
}
