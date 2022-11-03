import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Bus {
    public static void minFunction(int n, int m) {
        int min;
        if (m - n > 0) {
            min = 100 * n + 100 * (m - n);
        } else {
            min = 100 * n;
        }
        System.out.println(min);
    }

    public static void maxFunction(int n, int m) {
        int max;
        if (m - 1 >= 0) {
            max = (m - 1) * 100 + n * 100;
        } else {
            max = 100 * 2;
        }
        System.out.println(max);
    }

    public static void main(String[] args) throws Exception {
        int i, j, k;

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int M = Integer.parseInt(br.readLine());

        br.close();

        minFunction(N, M);
        maxFunction(N, M);

    }
}
