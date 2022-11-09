import java.util.Scanner;

class GreedyCoins {

    public static int minNumCoins(int coins[], int sum) {

        for (int i = 0; i < coins.length - 1; i++) {
            for (int j = 0; j < coins.length - i - 1; j++) {
                if (coins[j] < coins[j + 1]) {
                    int tmp = coins[j];
                    coins[j] = coins[j + 1];
                    coins[j + 1] = tmp;
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < coins.length; i++) {
            while (sum - coins[i] >= 0) {
                sum -= coins[i];
                ++cnt;
            }
        }
        return cnt;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        String coinsStringLine = input.nextLine();
        String coinsString[] = coinsStringLine.split(" ");
        int coins[] = new int[coinsString.length];
        for (int i = 0; i < coinsString.length; i++) {
            coins[i] = Integer.parseInt(coinsString[i]);
        }

        int sum = input.nextInt();

        System.out.println(minNumCoins(coins, sum));
    }
}
