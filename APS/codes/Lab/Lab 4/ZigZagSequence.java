import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class ZigZagSequence {

    static int najdiNajdolgaCikCak(int a[]) {
        // Vasiot kod tuka
        int[] cnt = new int[a.length];
        Arrays.fill(cnt, 1);
        for (int i = 1; i < a.length; i++) {
            if ((a[i] > 0 && a[i - 1] < 0) || (a[i] < 0 && a[i - 1] > 0)) {
                cnt[i] = cnt[i - 1] + 1;
            }
        }
        return Arrays.stream(cnt).max().getAsInt();
    }

    public static void main(String[] args) throws Exception {
        int i, j, k;

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int a[] = new int[N];
        for (i = 0; i < N; i++)
            a[i] = Integer.parseInt(br.readLine());

        int rez = najdiNajdolgaCikCak(a);
        System.out.println(rez);

        br.close();

    }

}
