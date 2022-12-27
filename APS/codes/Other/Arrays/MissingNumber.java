package Youtube;

// Find the missing number in array

public class MissingNumber {

    public static int findMissingNumber(int[] arr) {
        int n = arr.length + 1;
        int sum = n * (n + 1) / 2;
        for (int num : arr) {
            sum = sum - num;
        }
        return sum;
    }

    public void arrayDemo() {
        int[] arr = {1, 3, 2, 5, 6, 7, 8, 9};
        System.out.println(findMissingNumber(arr));
    }

    public static void main(String[] args) {
        MissingNumber miss = new MissingNumber();
        miss.arrayDemo();
    }
}
