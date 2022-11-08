import java.util.Scanner;

public class MinDistance {

    public static float minimalDistance(float points[][]) {
        //Vasiot kod ovde
        if (points.length < 2)
            return 0;

        float smallest = (float) Math.sqrt(Math.pow(points[1][0] - points[0][0], 2) + Math.pow(points[1][1] - points[0][1], 2));

        for (int i = 0; i < points.length; i++) {
            for (int j = (i + 1 < points.length ? i + 1 : points.length); j < points.length; j++) {
                float distance = (float) Math.sqrt(Math.pow(points[j][0] - points[i][0], 2) + Math.pow(points[j][1] - points[i][1], 2));
                smallest = distance < smallest ? distance : smallest;
            }
        }
        return smallest;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int N = input.nextInt();

        float points[][] = new float[N][2];

        for (int i = 0; i < N; i++) {
            points[i][0] = input.nextFloat();
            points[i][1] = input.nextFloat();
        }

        System.out.printf("%.2f\n", minimalDistance(points));
    }
}
