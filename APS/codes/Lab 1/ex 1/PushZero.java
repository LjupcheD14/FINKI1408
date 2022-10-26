import java.io.*;
import java.util.Scanner;

public class PushZero {
    static void pushZerosToEnd(int arr[], int n) {
        int tmp = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] != 0) {
                arr[tmp] = arr[i];
                tmp++;
            }
        }
        for (int i = tmp; i < n; i++) {
            arr[i] = 0;
        }

    }

    public static void main(String[] args) {
        int n;

        Scanner input = new Scanner(System.in);
        n = input.nextInt();
        int[] array = new int[n];
        for (int i = 0; i < n; i++) {
            array[i] = input.nextInt();
        }

        pushZerosToEnd(array, n);

        System.out.println("Transformiranata niza e:");
        for (int i = 0; i < n; i++) {
            System.out.printf("%d ", array[i]);
        }

    }
}
