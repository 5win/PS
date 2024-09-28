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
        List<Character> lst = new LinkedList<>();
        s.chars().forEach(c -> lst.add((char)c));

        int n = Integer.parseInt(br.readLine());

        ListIterator<Character> cursor = lst.listIterator(lst.size());


        for(int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");

            if(input[0].equals("L")) {
                if(cursor.hasPrevious())
                    cursor.previous();
            } else if(input[0].equals("D")) {
                if(cursor.hasNext())
                    cursor.next();
            } else if(input[0].equals("B")) {
                if(cursor.hasPrevious()) {
                    cursor.previous();
                    cursor.remove();
                }
            } else if(input[0].equals("P")) {
                cursor.add(input[1].toCharArray()[0]);
            }
        }

        for(char c : lst) {
            bw.write(c);
        }

        bw.flush();
        bw.close();
    }
}
