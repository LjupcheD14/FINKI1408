import java.util.Scanner;

public class FractionalKnapsackGreedy {

    public static void sortProfitAndWeights(int p[], int w[]) {
        for (int i = 0; i < p.length; i++) {
            for (int j = i + 1; j < p.length; j++) {
                if ((p[i] / (float) w[i]) < (p[j] / (float) w[j])) {
                    int tmpP = p[i];
                    int tmpW = w[i];
                    p[i] = p[j];
                    w[i] = w[j];
                    p[j] = tmpP;
                    w[j] = tmpW;
                }
            }
        }
    }

    public static float getFractKnpMaxProfit(int p[], int w[], int C) {
        sortProfitAndWeights(p, w);
        float profit = 0;
        for (int i = 0; i < p.length; i++) {
            if (C > w[i]) {
                C -= w[i];
                profit += p[i];
            } else {
                float x = C / (float) w[i];
                profit += x * p[i];
                C = 0;
                break;
            }
        }
        return profit;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int p[] = new int[n];
        int w[] = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = input.nextInt();
            w[i] = input.nextInt();
        }
        int C = input.nextInt();

        System.out.println(getFractKnpMaxProfit(p, w, C));
    }
}
