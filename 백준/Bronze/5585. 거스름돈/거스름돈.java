import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int cost = Integer.parseInt(br.readLine());
        int remain = 1000 - cost;

        int res = 0;
        res += remain / 500;
        remain %= 500;
        res += remain / 100;
        remain %= 100;
        res += remain / 50;
        remain %= 50;
        res += remain / 10;
        remain %= 10;
        res += remain / 5;
        remain %= 5;
        res += remain / 1;
        remain %= 1;

        bw.write(res + "\n");

        bw.flush();
        bw.close();
    }
}
