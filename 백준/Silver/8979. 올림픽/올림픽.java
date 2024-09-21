import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static class Country implements Comparable<Country> {
        int num;
        int g, s, b;

        public Country(int num, int g, int s, int b) {
            this.num = num;
            this.g = g;
            this.s = s;
            this.b = b;
        }

        public int compareTo(Country o) {
            return this.num < o.num ? -1 : 1;
        }

        public int compCountry(Country o) {
            if(this.g == o.g) {
                if(this.s == o.s) {
                    if(this.b == o.b) {
                        return 0;
                    }
                    return this.b > o.b ? -1 : 1;
                }
                return this.s > o.s ? -1 : 1;
            }
            return this.g > o.g ? -1 : 1;
        }
    }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n, k;
        List<Country> arr = new ArrayList<>();

        n = sc.nextInt();
        k = sc.nextInt();

        for(int i = 0; i < n; i++) {
            int num, g, s, b;
            num = sc.nextInt();
            g = sc.nextInt();
            s = sc.nextInt();
            b = sc.nextInt();
            arr.add(new Country(num, g, s, b));
        }
        Collections.sort(arr);

        int res = 1;
        Country target = arr.get(k  -1);
        for(int i = 0; i < n; i++) {
            if(i == k - 1) continue;
            if(target.compCountry(arr.get(i)) == 1) {
                res++;
            }
        }
        System.out.println(res);

    }
}
