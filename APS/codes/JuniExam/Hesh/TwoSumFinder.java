// Given an array of integers, find the two numbers that add up to a specific target sum using a hash set.

import java.util.HashSet;
import java.util.Set;

public class TwoSumFinder {
    public static int[] findTwoSum(int[] nums, int target) {
        // Create a hash set to store the complement of each number
        Set<Integer> complementSet = new HashSet<>();

        // Iterate over the array
        for (int num : nums) {
            int complement = target - num;

            // Check if the complement exists in the hash set
            if (complementSet.contains(complement)) {
                // Return the indices of the two numbers
                int index1 = getIndex(nums, num);
                int index2 = getIndex(nums, complement);
                return new int[]{index1, index2};
            }

            // Add the current number to the hash set
            complementSet.add(num);
        }

        // Return an empty array if no two numbers add up to the target sum
        return new int[]{};
    }

    private static int getIndex(int[] nums, int target) {
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == target) {
                return i;
            }
        }
        return -1; // Not found
    }

    public static void main(String[] args) {
        int[] nums = {2, 7, 11, 15};
        int target = 9;
        int[] result = findTwoSum(nums, target);
        if (result.length == 2) {
            int index1 = result[0];
            int index2 = result[1];
            System.out.println("Indices of two numbers that add up to " + target + ": " + index1 + ", " + index2);
            System.out.println("Numbers: " + nums[index1] + ", " + nums[index2]);
        } else {
            System.out.println("No two numbers found that add up to " + target);
        }
    }
}
