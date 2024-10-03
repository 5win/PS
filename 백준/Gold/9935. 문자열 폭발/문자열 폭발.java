import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        char[] str = br.readLine().toCharArray();
        char[] bomb = br.readLine().toCharArray();
        int bLen = bomb.length;
        List<Character> arr = new ArrayList<>();

        for(int i = 0; i < str.length; i++) {
            arr.add(str[i]);
            if(arr.size() >= bLen) {
                boolean canBomb = true;
                for(int j = 0; j < bLen; j++) {
                    if(arr.get(arr.size() - bLen + j) != bomb[j]) {
                        canBomb = false;
                        break;
                    }
                }
                if(canBomb) {
                    for(int j = 0; j < bLen; j++)
                        arr.remove(arr.size() - 1);
                }
            }
        }
        if(arr.size() == 0) {
            bw.write("FRULA");
        } else {
            for(char c : arr)
                bw.write(c);
        }

        bw.flush();
        bw.close();
    }
}
