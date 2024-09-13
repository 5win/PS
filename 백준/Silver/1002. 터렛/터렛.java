import java.util.*;
import java.io.*;

public class Main {

    static int x1, y1, r1, x2, y2, r2;

    static double calcDist(int r1, int c1, int r2, int c2) {
        int yLen = Math.abs(r1 - r2);
        int xLen = Math.abs(c1 - c2);

        return Math.sqrt(yLen * yLen + xLen * xLen);
    }

    public static void main(String[] args) throws IOException {

        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();
        while(t-- != 0) {
            x1 = sc.nextInt();
            y1 = sc.nextInt();
            r1 = sc.nextInt();
            x2 = sc.nextInt();
            y2 = sc.nextInt();
            r2 = sc.nextInt();
            
            double dist = calcDist(x1, y1, x2, y2);

            if(x1 == x2 && y1 == y2 && r1 == r2)
                System.out.println(-1);
            else if(r1 + r2 > dist && Math.abs(r1 - r2) < dist)
                System.out.println(2);
            else if(r1 + r2 == dist || Math.abs(r1 - r2) == dist)
                System.out.println(1); 
            else
                System.out.println(0);
        }
    }
}
