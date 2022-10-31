import java.util.Scanner;

public class Initials {

    public static String printInitials(String name) {
        
        int idxLastWhitespace = name.lastIndexOf(' ');
        return name.charAt(0) + name.substring(idxLastWhitespace + 1, idxLastWhitespace + 2);
    }

    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        String name;
        input.nextLine();

        for (int i = 0; i < n; i++) {
            name = input.nextLine();
            printInitials(name);
            System.out.println(printInitials(name).toUpperCase());
        }
    }
}

