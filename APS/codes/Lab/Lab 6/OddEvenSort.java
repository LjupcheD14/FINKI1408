import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class OddEvenSort {

    static void oddEvenSort(int a[], int n) {
        // Vasiot kod tuka
        int[] newArray = new int[n];
        Arrays.sort(a);

        int x = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 1) {
                newArray[x] = a[i];
                x++;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            if (a[i] % 2 == 0) {
                newArray[x] = a[i];
                x++;
            }
        }

        for (int i = 0; i < newArray.length; i++) {
            a[i] = newArray[i];
        }

    }

    public static void main(String[] args) throws IOException {
        int i;
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
        String s = stdin.readLine();
        int n = Integer.parseInt(s);

        s = stdin.readLine();
        String[] pom = s.split(" ");
        int[] a = new int[n];
        for (i = 0; i < n; i++)
            a[i] = Integer.parseInt(pom[i]);
        oddEvenSort(a, n);
        for (i = 0; i < n - 1; i++)
            System.out.print(a[i] + " ");
        System.out.print(a[i]);
    }
}
