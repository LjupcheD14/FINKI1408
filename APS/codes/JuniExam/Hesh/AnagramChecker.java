// Write a function to check if two strings are anagrams using a hash map.

import java.util.HashMap;
import java.util.Map;

public class AnagramChecker {
    public static boolean areAnagrams(String str1, String str2) {
        // Check if the lengths of the strings are different
        if (str1.length() != str2.length()) {
            return false;
        }

        // Create hash maps to store character frequencies
        Map<Character, Integer> map1 = new HashMap<>();
        Map<Character, Integer> map2 = new HashMap<>();

        // Populate the hash maps with character frequencies of str1 and str2
        for (int i = 0; i < str1.length(); i++) {
            char c1 = str1.charAt(i);
            char c2 = str2.charAt(i);

            // Increment the count for character c1 in map1
            map1.put(c1, map1.getOrDefault(c1, 0) + 1);

            // Increment the count for character c2 in map2
            map2.put(c2, map2.getOrDefault(c2, 0) + 1);
        }

        // Compare the hash maps
        return map1.equals(map2);
    }

    public static void main(String[] args) {
        String str1 = "listen";
        String str2 = "silent";
        System.out.println("Are '" + str1 + "' and '" + str2 + "' anagrams? " + areAnagrams(str1, str2)); // Output: true

        String str3 = "hello";
        String str4 = "world";
        System.out.println("Are '" + str3 + "' and '" + str4 + "' anagrams? " + areAnagrams(str3, str4)); // Output: false
    }
}
