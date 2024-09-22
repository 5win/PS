import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static String str;

    static boolean isAeiou(char c) {
        char[] lst = {'a', 'e', 'i', 'o', 'u'};
        for(char i : lst) {
            if(c == i) return true;
        } 
        return false;
    }

    static boolean checkFirst() {
        for(int i = 0; i < str.length(); i++) {
            if(isAeiou(str.charAt(i))) return true;
        }
        return false;
    }

    static boolean checkSecond() {
        for(int i = 0; i < str.length() - 2; i++) {
            char c1 = str.charAt(i);
            char c2 = str.charAt(i + 1);
            char c3 = str.charAt(i + 2);

            if(isAeiou(c1) && isAeiou(c2) && isAeiou(c3)) return false;
            if(!isAeiou(c1) && !isAeiou(c2) && !isAeiou(c3)) return false;
        }
        return true;
    }

    static boolean checkThird() {
        for(int i = 0; i < str.length() - 1; i++) {
            char c1 = str.charAt(i);
            char c2 = str.charAt(i + 1);

            if(c1 == 'e' && c2 == 'e') continue;
            else if(c1 == 'o' && c2 == 'o') continue;
            else if(c1 == c2) return false;
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while(true) {
            str = sc.nextLine();
            if(str.equals("end")) break;
            if(checkFirst() && checkSecond() && checkThird()) {
                System.out.println("<" + str + ">" + " is acceptable.");
            } else {
                System.out.println("<" + str + ">" + " is not acceptable.");
            }
        }
    }
}
