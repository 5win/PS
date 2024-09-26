import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static int n;
    static List<Integer>[] team = new ArrayList[201];

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in); 

        int t = sc.nextInt();
        List<Integer> lst = new ArrayList<>();

        while (t-- > 0) {
            n = sc.nextInt();
            lst.clear();
            int[] cnt = new int[201];

            for(int i = 0; i < n; i++) {
                int cur = sc.nextInt();
                lst.add(cur);
                cnt[cur]++;
            }
            
            for(int i = 0; i < 201; i++) {
                team[i] = new ArrayList<>();
            }
            int score = 1;
            for(int i = 0; i < n; i++) {
                int cur = lst.get(i);
                if(cnt[cur] < 6) continue;
                team[cur].add(score++);
            }

            int minTeamNum = 0;
            int minScore = 0;
            for(int i = 1; i < 201; i++) {
                if(cnt[i] < 6) continue;
                int sum = 0;
                for(int j = 0; j < 4; j++) {
                    sum += team[i].get(j);
                }
                if(minScore > sum || minTeamNum == 0) {
                    minScore = sum;
                    minTeamNum = i;
                } else if(minScore == sum && team[minTeamNum].get(4) > team[i].get(4)) {
                    minScore = sum;
                    minTeamNum = i;
                }
            }
            System.out.println(minTeamNum);
        }
    }
}
