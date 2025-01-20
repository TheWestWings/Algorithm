import java.util.*;
public class chz {
    public static void main(String[] args) {
        int a = 0;
        for (int i = 100000000; i <= 999999999; i++) {
            if (i % 9 == 0 && i / 10 % 8 == 0 && i / 100 % 7 == 0 && i / 1000 % 6 == 0 && i / 10000 % 5 == 0 && i / 100000 % 4 ==0 && i / 1000000 % 3 == 0 && i / 10000000 % 2 == 0){
                a = i;
                break;
            }
        }
        System.out.println(a);
        }
    }
 

