package Youtube;

// Check if given string is palindrome

public class isPalindrome {

    public boolean isPalindromeFunction(String word) {
        char[] charArray = word.toCharArray();
        int start = 0;
        int end = word.length() - 1;

        while (start < end) {
            if (charArray[start] != charArray[end]) {
                return false;
            }

            start++;
            end--;
        }
        return true;
    }

    public static void main(String[] args) {
        isPalindrome isP = new isPalindrome();
        if(isP.isPalindromeFunction("madam")){
            System.out.println("Is a palindrome");
        } else{
            System.out.println("Is not a palindrome");
        }
    }
}
