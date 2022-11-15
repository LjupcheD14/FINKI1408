import java.io.BufferedReader;
import java.io.InputStreamReader;

public class ArithmeticExpression {

    // funkcija za presmetuvanje na izrazot pocnuvajki
    // od indeks l, zavrsuvajki vo indeks r
    static int presmetaj(char c[], int l, int r) {
        // Vasiot kod tuka
        int start = 0;
        int mid = 0;
        int end = 0;
        for (int i = l + 1; i <= r; i++) {
            if (c[i] == '(')
                start++;
            if (c[i] == ')')
                end++;
            if (start == end) {
                mid = i + 1;
                break;
            }
        }
        if (c[l + 1] == '(' && c[mid + 1] == '(') {
            if (c[mid] == '+')
                return presmetaj(c, l + 1, mid - 1) + presmetaj(c, mid + 1, r - 1);
            else
                return presmetaj(c, l + 1, mid - 1) - presmetaj(c, mid + 1, r - 1);
        } else if (c[l + 1] == '(') {
            if (c[mid] == '+')
                return presmetaj(c, l + 1, mid - 1) + Integer.parseInt(String.valueOf(c[mid + 1]));
            else
                return presmetaj(c, l + 1, mid - 1) - Integer.parseInt(String.valueOf(c[mid + 1]));
        } else if (c[mid + 1] == '(') {
            if (c[mid] == '+')
                return Integer.parseInt(String.valueOf(c[l + 1])) + presmetaj(c, mid + 1, r - 1);
            else
                return Integer.parseInt(String.valueOf(c[l + 1])) - presmetaj(c, mid + 1, r - 1);
        } else {
            if (c[mid] == '+')
                return Integer.parseInt(String.valueOf(c[l + 1])) + Integer.parseInt(String.valueOf(c[mid + 1]));
            else
                return Integer.parseInt(String.valueOf(c[l + 1])) - Integer.parseInt(String.valueOf(c[mid + 1]));
        }

    }

    public static void main(String[] args) throws Exception {
        int i, j, k;

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String expression = br.readLine();
        char exp[] = expression.toCharArray();

        int rez = presmetaj(exp, 0, exp.length - 1);
        System.out.println(rez);

        br.close();

    }

}
