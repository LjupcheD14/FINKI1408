import java.util.Scanner;

import static java.lang.Character.toUpperCase;

public class Initials {

    static void printInitials(String name) {
        name = name.toUpperCase();
        char first = name.charAt(0);
        StringBuilder initials = new StringBuilder(String.valueOf(first));
        for (int i = 0; i < name.length(); i++) {
            int Compare = Character.compare(name.charAt(i), ' ');
            if(Compare==0){
                char afterSpace = name.charAt(i+1);
                initials.append(afterSpace);
            }
        }
        System.out.print(initials);
//        int idxLastWhitespace = name.lastIndexOf(' ');
//        return name.charAt(0) + name.substring(idxLastWhitespace + 1, idxLastWhitespace + 2);
    }

    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        String name;
        input.nextLine();

        for (int i = 0; i < n; i++) {
            name = input.nextLine();
            printInitials(name);
            System.out.println();
        }
    }
}

