import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static Set<Integer> set = new HashSet<>();

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String inputNum = br.readLine();
        int n = Integer.parseInt(inputNum);

        while(n-- > 0) {
            String[] input = br.readLine().split(" ");
            String op = input[0];

            if(op.equals("add")) {
                int num = Integer.parseInt(input[1]);
                set.add(num);
                
            } else if(op.equals("remove")) {
                int num = Integer.parseInt(input[1]);
                set.remove(num);
            } else if(op.equals("check")) {
                int num = Integer.parseInt(input[1]);
                if(set.contains(num)) {
                    bw.write("1\n");
                } else {
                    bw.write("0\n");
                }
            } else if(op.equals("toggle")) {
                int num = Integer.parseInt(input[1]);
                if(set.contains(num)) {
                    set.remove(num);
                } else {
                    set.add(num);
                }
            } else if(op.equals("all")) {
                set.clear();
                IntStream.rangeClosed(1, 20).forEach(v -> set.add(v));
            } else {
                set.clear();
            }
        }

        bw.flush();
        bw.close();
    }
}
