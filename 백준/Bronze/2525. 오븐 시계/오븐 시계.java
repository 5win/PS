import java.util.*;

public class Main {

    static int a, b, c;

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        a = sc.nextInt();
        b = sc.nextInt();
        c = sc.nextInt();

        int h, m;
        h = (a + (b + c) / 60) % 24;
        m = (b + c) % 60;
        System.out.println(h + " " + m);
    }
}