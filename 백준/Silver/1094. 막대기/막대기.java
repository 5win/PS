import java.util.*;

public class Main {
    static int x;

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        x = sc.nextInt();

        int cnt = 0;
        for(int i = 0; i <= 6; i++) {
            if((x & (1 << i)) > 0) cnt++;
        }
        System.out.println(cnt);
    }
}