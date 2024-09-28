import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static class Team implements Comparable<Team> {
        public int[] score = new int[101];
        public int id = -1;
        public int cnt = 0;
        public int time = 0;

        public int sum() {
            return Arrays.stream(score).sum();
        }

        public int compareTo(Team o) {

            int sum1 = this.sum();
            int sum2 = o.sum();
            if(sum1 == sum2) {
                if(cnt == o.cnt) {
                    return time - o.time;
                }
                return cnt - o.cnt;
            }
            return sum2 - sum1;
        }
    }

    static int n, k, t, m;
    static Team[] teams = new Team[101];

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());

        for(int curT = 0; curT < T; curT++) {
            String[] input = br.readLine().split(" ");
            n = Integer.parseInt(input[0]); k = Integer.parseInt(input[1]);
            t = Integer.parseInt(input[2]); m = Integer.parseInt(input[3]);

            for(int i = 0; i < 101; i++)
                teams[i] = new Team();

            for(int i = 0; i < m; i++) {
                input = br.readLine().split(" ");
                int id = Integer.parseInt(input[0]) - 1;
                int num = Integer.parseInt(input[1]);
                int score = Integer.parseInt(input[2]);

                int prevScore = teams[id].score[num];
                teams[id].id = id;
                teams[id].score[num] = prevScore < score ? score : prevScore;
                teams[id].cnt++;
                teams[id].time = i;
            }

            Arrays.sort(teams);


            for(int i = 0; i <= n; i++) {
                if(teams[i].id == t - 1) {
                    bw.write(String.valueOf(i + 1) + "\n");
                }
            }
        }

        bw.flush();
        bw.close();
    }
}
