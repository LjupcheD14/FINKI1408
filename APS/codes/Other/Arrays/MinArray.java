package Youtube;

// Find min in array

public class MinArray {
    public int findMin(int[] arr) {
        if (arr == null || arr.length == 0) {
            throw new IllegalArgumentException("Invalid input");
        }

        int min = arr[0];
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] < min) {
                min = arr[i];
            }
        }
        return min;
    }

    public static void main(String[] args) {
        int[] arr = {3, 2, 1, 6, 7, 8, 9, 12, 2432, 12};
        MinArray test = new MinArray();
        System.out.println(test.findMin(arr));
    }
}
