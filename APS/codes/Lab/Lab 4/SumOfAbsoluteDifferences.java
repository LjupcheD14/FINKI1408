import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class SumOfAbsoluteDifferences {

    static int solve(int numbers[], int N, int K) {
        // vasiot kod ovde
        // mozete da napisete i drugi funkcii dokolku vi se potrebni
        int[][] best = new int[K + 1][N + 1];
        for (int i = 2; i <= K; i++) {
            for (int j = i - 1; j < N; j++) {
                for (int k = j - 1; k >= i - 2; k--) {
                    best[i][j] = Math.max(best[i][j], best[i - 1][k] + Math.abs(numbers[k] - numbers[j]));
                }
            }
        }
        int najgolem = 0;
        for (int i = K - 1; i < N; i++) {
            najgolem = Math.max(najgolem, best[K][i]);
        }
        return najgolem;
    }

    public static void main(String[] args) throws Exception {
        int i, j, k;

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        int numbers[] = new int[N];

        st = new StringTokenizer(br.readLine());
        for (i = 0; i < N; i++) {
            numbers[i] = Integer.parseInt(st.nextToken());
        }

        int res = solve(numbers, N, K);
        System.out.println(res);

        br.close();

    }

}
