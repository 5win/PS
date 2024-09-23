import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static int n;
    static String[] cookie = new String[1001];
    static int[] heart = new int[2];
    static int[] spineEnd = new int[2];
    static int[] res = new int[5];

    static void findHead() {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(cookie[i].charAt(j) == '*') {
                    heart[0] = i + 1;
                    heart[1] = j;
                    return;
                }
            }
        }
    }

    static int calcSpine() {
        int i;
        for(i = heart[0]; i < n; i++) {
            if(cookie[i].charAt(heart[1]) == '_') {
                spineEnd[0] = i - 1;
                spineEnd[1] = heart[1];
                break;
            }
        }
        return i - heart[0] - 1;
    }

    static int calcLeftArm() {
        int j;
        for(j = heart[1]; j >= 0; j--) {
            if(cookie[heart[0]].charAt(j) == '_') {
                return heart[1] - j - 1;
            }
        }
        return heart[1] - j - 1;
    }

    static int calcRightArm() {
        int j;
        for(j = heart[1]; j < n; j++) {
            if(cookie[heart[0]].charAt(j) == '_') {
                return j - heart[1] - 1;
            }
        }
        return j - heart[1] - 1;
    }

    static int calcLeftLeg() {
        int i, j = spineEnd[1] - 1;
        for(i = spineEnd[0] + 1; i < n; i++) {
            if(cookie[i].charAt(j) == '_') {
                return i - (spineEnd[0] + 1);
            }
        }
        return i - (spineEnd[0] + 1);
    }

    static int calcRightLeg() {
        int i, j = spineEnd[1] + 1;
        for(i = spineEnd[0] + 1; i < n; i++) {
            if(cookie[i].charAt(j) == '_') {
                return i - (spineEnd[0] + 1);
            }
        }
        return i - (spineEnd[0] + 1);
    }
    static void solve() {
        findHead();
        res[0] = calcLeftArm();
        res[1] = calcRightArm();
        res[2] = calcSpine();
        res[3] = calcLeftLeg();
        res[4] = calcRightLeg();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        sc.nextLine();

        for(int i = 0; i < n; i++) {
            cookie[i] = sc.nextLine();
        }
        solve();

        System.out.println((heart[0] + 1) + " " + (heart[1] + 1));
        for(int i = 0; i < 5; i++) {
            System.out.print(res[i] + " ");
        }
    }
}
