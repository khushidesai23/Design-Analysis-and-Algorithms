//KHUSHI DESAI

//Matrix Multiplication using devide and conquer method with recursive function

import java.util.Scanner;

public class MatrixMul {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of the matrix");
        int n = sc.nextInt();
        int[][] a = new int[n][n];
        int[][] b = new int[n][n];
        int[][] c = new int[n][n];
        System.out.println("Enter the elements of the first matrix");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = sc.nextInt();
            }
        }
        System.out.println("Enter the elements of the second matrix");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                b[i][j] = sc.nextInt();
            }
        }
        c = multiply(a, b, n);
        System.out.println("The product of the two matrices is");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(c[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static int[][] multiply(int[][] a, int[][] b, int n) {
        int[][] c = new int[n][n];
        if (n == 1) {
            c[0][0] = a[0][0] * b[0][0];
        } else {
            int[][] a11 = new int[n / 2][n / 2];
            int[][] a12 = new int[n / 2][n / 2];
            int[][] a21 = new int[n / 2][n / 2];
            int[][] a22 = new int[n / 2][n / 2];
            int[][] b11 = new int[n / 2][n / 2];
            int[][] b12 = new int[n / 2][n / 2];
            int[][] b21 = new int[n / 2][n / 2];
            int[][] b22 = new int[n / 2][n / 2];
            int[][] c11 = new int[n / 2][n / 2];
            int[][] c12 = new int[n / 2][n / 2];
            int[][] c21 = new int[n / 2][n / 2];
            int[][] c22 = new int[n / 2][n / 2];
            int[][] p1 = new int[n / 2][n / 2];
            int[][] p2 = new int[n / 2][n / 2];
            int[][] p3 = new int[n / 2][n / 2];
            int[][] p4 = new int[n / 2][n / 2];
            int[][] p5 = new int[n / 2][n / 2];
            int[][] p6 = new int[n / 2][n / 2];
            int[][] p7 = new int[n / 2][n / 2];
            for (int i = 0; i < n / 2; i++) {
                for (int j = 0; j < n / 2; j++) {
                    a11[i][j] = a[i][j];
                    a12[i][j] = a[i][j + n / 2];
                    a21[i][j] = a[i + n / 2][j];
                    a22[i][j] = a[i + n / 2][j + n / 2];
                    b11[i][j] = b[i][j];
                    b12[i][j] = b[i][j + n / 2];
                    b21[i][j] = b[i + n / 2][j];
                    b22[i][j] = b[i + n / 2][j + n / 2];
                }
            }
            p1 = multiply(a11, subtract(b12, b22, n / 2), n / 2);
            p2 = multiply(add(a11, a12, n / 2), b22, n / 2);
            p3 = multiply(add(a21, a22, n / 2), b11, n / 2);
            p4 = multiply(a22, subtract(b21, b11, n / 2), n / 2);
            p5 = multiply(add(a11, a22, n / 2), add(b11, b22, n / 2), n / 2);
            p6 = multiply(subtract(a12, a22, n / 2), add(b21, b22, n / 2), n / 2);
            p7 = multiply(subtract(a11, a21, n / 2), add(b11, b12, n / 2), n / 2);
            c11 = add(subtract(add(p5, p4, n / 2), p2, n / 2), p6, n / 2);
            c12 = add(p1, p2, n / 2);
            c21 = add(p3, p4, n / 2);
            c22 = subtract(subtract(add(p5, p1, n / 2), p3, n / 2), p7, n / 2);
            for (int i = 0; i < n / 2; i++) {
                for (int j = 0; j < n / 2; j++) {
                    c[i][j] = c11[i][j];
                    c[i][j + n / 2] = c12[i][j];
                    c[i + n / 2][j] = c21[i][j];
                    c[i + n / 2][j + n / 2] = c22[i][j];
                }
            }
        }
        return c;
    }

    public static int[][] add(int[][] a, int[][] b, int n) {
        int[][] c = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                c[i][j] = a[i][j] + b[i][j];
            }
        }
        return c;
    }

    public static int[][] subtract(int[][] a, int[][] b, int n) {
        int[][] c = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                c[i][j] = a[i][j] - b[i][j];
            }
        }
        return c;
    }

}
//T(n)=8*T(n/2)+O(n^2)
