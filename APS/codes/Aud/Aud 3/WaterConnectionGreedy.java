import java.util.ArrayList;
import java.util.Scanner;

public class WaterConnectionGreedy {
    public static ArrayList<ArrayList<Integer>> findTanksAndTaps(int houses[][]) {
        ArrayList<ArrayList<Integer>> rez = new ArrayList<>();

        for (int i = 0; i < houses.length; i++) {
            if (houses[i][3] == 0 && houses[i][2] == -1) {
                int pom = i;
                int min_d = houses[i][1];
                int next = houses[i][0];
                while (next != -1) {
                    if (houses[pom][1] < min_d) {
                        min_d = houses[pom][1];
                    }
                    houses[pom][3] = 1;
                    pom = next;
                    next = houses[next][0];
                }
                if (pom != i) {
                    houses[pom][3] = 1;
                    ArrayList<Integer> tmp = new ArrayList<>();
                    tmp.add(i);
                    tmp.add(pom);
                    tmp.add(min_d);
                    rez.add(tmp);
                }
            }
        }
        return rez;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();
        int p = input.nextInt();

        int houses[][] = new int[n][4];
        for (int i = 0; i < n; i++) {
            houses[i][0] = -1; // kon koja kukja ima izlezna cevka
            houses[i][1] = 0; // dijametarot na izleznata cevka
            houses[i][2] = -1; //od koja kukja ima vlezna cevka
            houses[i][3] = 0; // dali e vekje povrzana kukjata
        }

        for (int i = 0; i < p; i++) {
            int h1 = input.nextInt();
            int h2 = input.nextInt();
            houses[h1][0] = h2;
            houses[h1][1] = input.nextInt();
            houses[h2][2] = h1;
        }

        ArrayList<ArrayList<Integer>> tanksAndTaps = findTanksAndTaps(houses);

        System.out.println(tanksAndTaps.size());

        for (int i = 0; i < tanksAndTaps.size(); i++) {
            System.out.println(tanksAndTaps.get(i).get(0) + " " + tanksAndTaps.get(i).get(1) + " " + tanksAndTaps.get(i).get(2));
        }
    }
}
