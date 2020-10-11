package Algorithms.Graph_Algorithms.Flood_Fill;

import java.util.Scanner;

public class Flood_Fill {

    private static final Scanner scanner = new Scanner(System.in);
    private static final int length = 8;
    private static final int width = 8;

    private static boolean isValid(int x, int y) {

        return x >= 0 && x < length && y >= 0 && y < width;
    }

    private static void floodFill(int[][] screen, int x, int y, int prev_color, int new_color) {

        if (isValid(x, y) && screen[x][y] == prev_color) {

            screen[x][y] = new_color;
            floodFill(screen, x + 1, y, prev_color, new_color);
            floodFill(screen, x - 1, y, prev_color, new_color);
            floodFill(screen, x, y + 1, prev_color, new_color);
            floodFill(screen, x, y - 1, prev_color, new_color);
        }
    }

    public static void main(String[] args) {

        int[][] screen = { { 1, 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1, 0, 0 }, { 1, 0, 0, 1, 1, 0, 1, 1 },
                { 1, 2, 2, 2, 2, 0, 1, 0 }, { 1, 1, 1, 2, 2, 0, 1, 0 }, { 1, 1, 1, 2, 2, 2, 2, 0 },
                { 1, 1, 1, 1, 1, 2, 1, 1 }, { 1, 1, 1, 1, 1, 2, 2, 1 } };

        int x, y, prev_color, new_color;
        System.out.println("Enter the co-ordinates (X,Y) of point on the screen");
        x = scanner.nextInt();
        y = scanner.nextInt();
        new_color = scanner.nextInt();
        prev_color = screen[x][y];
        floodFill(screen, x, y, prev_color, new_color);

        System.out.println("Updated Screen after flood fill");
        for (int[] row : screen) {

            for (int col : row) {

                System.out.print(col + " ");
            }
            System.out.println();
        }

    }
}
