package Youtube;

// Resize an array

public class ArrayUtil {
    public void printArray(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    public int[] resize(int[] arr, int capacity) {
        int[] temp = new int[capacity];
        for (int i = 0; i < arr.length; i++) {
            temp[i] = arr[i];
        }
        return temp;
    }

    public static void main(String[] args) {
        ArrayUtil arrayUtil = new ArrayUtil();
        int[] original = new int[]{5, 1, 2, 3, 5, 67};
        System.out.println("The size of original array is: " + original.length);
        original = arrayUtil.resize(original, 20);
        System.out.println("The size of orignal array after resize is: " + original.length);
    }
}
