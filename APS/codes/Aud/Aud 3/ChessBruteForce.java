import java.util.Scanner;

public class ChessBruteForce {
    public static boolean can_attack(int i1, int j1, int i2, int j2) {
        return (i1 == i2) || (j1 == j2) || (Math.abs(i1 - i2) == Math.abs(j1 - j2));
    }

    public static int number_of_combinations(int n) {
        int rez = 0;
        for (int i1 = 0; i1 < n; i1++) {
            for (int j1 = 0; j1 < n; j1++) {
                for (int i2 = 0; i2 < n; i2++) {
                    for (int j2 = 0; j2 < n; j2++) {
                        if (!can_attack(i1, j1, i2, j2)) {
                            rez++;
                        }
                    }
                }
            }
        }
        return rez;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Vnesi ja goleminata na shahovskata tabla: ");
        int n = input.nextInt();

        int rez = number_of_combinations(n);
        System.out.println("Brojot na nacini za postavuvanje e: " + rez);
    }

}
