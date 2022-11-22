// Најди ја најдолгата опаѓачка секвенца во една низа. Броевите во секвенцата не мора да се наоѓаат на последователни индекси во низата.


import java.lang.reflect.Array;
import java.util.Scanner;
import java.util.Arrays;


public class LDS {


    private static int najdolgaOpagackaSekvenca(int[] a) {

        // Vasiot kod tuka

        int[] longest = new int[a.length];
        Arrays.fill(longest, 1);

        for (int i = 1; i < a.length; i++) {
            for (int j = 0; j < i; j++) {
                if (a[i] < a[j] && longest[i] < longest[j] + 1) {
                    longest[i] = longest[j] + 1;
                }
            }
        }
        return Arrays.stream(longest).max().getAsInt();

    }

    public static void main(String[] args) {
        Scanner stdin = new Scanner(System.in);

        int n = stdin.nextInt();
        int a[] = new int[n];
        for (int i = 0; i < a.length; i++) {
            a[i] = stdin.nextInt();
        }
        System.out.println(najdolgaOpagackaSekvenca(a));
    }


}
