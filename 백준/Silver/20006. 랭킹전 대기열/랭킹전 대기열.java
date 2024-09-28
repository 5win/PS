import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static class Member implements Comparable<Member> {
        int level;
        String name;

        public Member(int l, String n) {
            level = l;
            name = n;
        }

        public int compareTo(Member m) {
            return name.compareTo(m.name);
        }
    }

    static int p, m;
    static List<List<Member>> lst = new ArrayList<>();

    static int roomNum(int level) {
        for(int i = 0; i < lst.size(); i++) {
            if(lst.get(i).size() == m) continue;
            Member first = lst.get(i).get(0);
            if(first.level - 10 <= level && level <= first.level + 10)
                return i; 
        }
        return -1;
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        p = Integer.parseInt(input[0]);
        m = Integer.parseInt(input[1]);

        for(int i = 0; i < p; i++) {
            input = br.readLine().split(" ");
            int level = Integer.parseInt(input[0]);
            String name = input[1];
            
            int rNum = roomNum(level);
            Member mem = new Member(level, name);
            if(rNum != -1) {
                lst.get(rNum).add(mem);
            } else {
                List<Member> tmp = new ArrayList<>();
                tmp.add(mem);
                lst.add(tmp);
            }
        }

        for(int i = 0; i < lst.size(); i++) {
            List<Member> cur = lst.get(i); 

            if(cur.size() < m)
                bw.write("Waiting!\n");
            else
                bw.write("Started!\n");

            Collections.sort(cur);
            for(Member member : cur) {
                bw.write(String.valueOf(member.level) + " " + member.name + "\n");
            }
        }

        bw.flush();
        bw.close();
    }
}
