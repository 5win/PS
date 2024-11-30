import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static class Pair<A, B> {
        A fir;
        B sec;
        public Pair(A a, B b) {
            fir = a;
            sec = b;
        }
    }

    static int n;
    static Map<Pair<Integer, Integer>, Integer> map = new HashMap<>();
    static List<Pair<Integer, Integer>> arr = new ArrayList<>();
    static List<Pair<Integer, Character>> res = new ArrayList<>();

    static void calcRow() {
        Collections.sort(arr, (a, b) -> a.fir - b.fir);

        int idx = 1;
        for(Pair<Integer, Integer> tank : arr) {
            int tankNum = map.get(tank);
            if(idx < tank.fir) {
                for(int i = 0; i < tank.fir - idx; i++) {
                    res.add(new Pair(tankNum, 'U'));
                }
            }
            idx++;
        }

        Collections.reverse(arr);
        idx = arr.size();
        for(Pair<Integer, Integer> tank : arr) {
            int tankNum = map.get(tank);
            if(idx > tank.fir) {
                for(int i = 0; i < idx - tank.fir; i++) {
                    res.add(new Pair(tankNum, 'D'));
                }
            }
            idx--;
        }
    }

    static void calcCol() {
        Collections.sort(arr, (a, b) -> a.sec - b.sec);

        int idx = 1;
        for(Pair<Integer, Integer> tank : arr) {
            int tankNum = map.get(tank);
            if(idx < tank.sec) {
                for(int i = 0; i < tank.sec - idx; i++) {
                    res.add(new Pair(tankNum, 'L'));
                }
            }
            idx++;
        }

        Collections.reverse(arr);
        idx = arr.size();
        for(Pair<Integer, Integer> tank : arr) {
            int tankNum = map.get(tank);
            if(idx > tank.sec) {
                for(int i = 0; i < idx - tank.sec; i++) {
                    res.add(new Pair(tankNum, 'R'));
                }
            }
            idx--;
        }
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());

        String[] input;
        for(int i = 0; i < n; i++) {
            input = br.readLine().split(" ");
            int y = Integer.parseInt(input[0]);
            int x = Integer.parseInt(input[1]);

            Pair<Integer, Integer> p = new Pair<>(y, x);
            arr.add(p);
            map.put(p, i + 1);
        }

        calcRow();
        calcCol();

        bw.write(res.size() + "\n");
        for(Pair<Integer, Character> i : res) {
            bw.write(i.fir + " " + i.sec + "\n");
        }

        bw.flush();
        bw.close();
    }
}
