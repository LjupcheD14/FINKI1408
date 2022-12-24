package Youtube;

// Print elements of an Array

package Youtube;

public class ArrayUtil {
    public void printArray(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        ArrayUtil arrayUtil = new ArrayUtil();
        arrayUtil.printArray(new int[]{1, 2, 3, 4, 5});
    }
}

