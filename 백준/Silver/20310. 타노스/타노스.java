import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String s = br.readLine();
        StringBuffer res = new StringBuffer();
        
        List<Integer> idx0 = new ArrayList<>();
        List<Integer> idx1 = new ArrayList<>();

        for(int i = 0; i < s.length(); i++) {
            if(s.charAt(i) == '0') {
                idx0.add(i);
            }
        }

        for(int i = s.length() - 1; i >= 0; i--) {
            if(s.charAt(i) == '1') {
                idx1.add(i);
            }
        }

        Collections.reverse(idx1);

        int s0 = 0;
        int s1 = idx1.size() / 2;
        while(s0 < idx0.size() / 2 || s1 < idx1.size()) {
            if(s0 == idx0.size() / 2) {
                res.append('1');
                s1++; 
            } else if(s1 == idx1.size()) {
                res.append('0');
                s0++;
            } else if(idx0.get(s0) < idx1.get(s1)) {
                res.append('0');
                s0++;
            } else {
                res.append('1');
                s1++;
            }
        }
        bw.write(res.toString());

        bw.flush();
        bw.close();
    }
}
