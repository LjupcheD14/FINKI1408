// Implement a hash function that takes a string as input and returns a unique hash code.

public class StringHashFunction {
    public static int hashCode(String str) {
        int hash = 0;
        for (int i = 0; i < str.length(); i++) {
            hash = hash * 31 + str.charAt(i);
        }
        return hash;
    }

    public static void main(String[] args) {
        String input = "Hello HASH";
        int hashCode = hashCode(input);
        System.out.println("Hash code of \"" + input + "\":" + hashCode);
    }
}
