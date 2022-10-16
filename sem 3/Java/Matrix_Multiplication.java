import java.util.*;

public class Matrix_Multiplication {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		System.out.println("Enter of rows and columns in the first matrix: ");
		System.out.print("Rows: ");
		int m = scan.nextInt();
		System.out.print("Cols: ");
		int n = scan.nextInt();
		int a[][] = new int[m][n];
		System.out.println("Enter the elements of the matrix: ");
		for (int i = 0; i < m; i++) 
		{
			for (int j = 0; j < n; j++) 
			{
				a[i][j] = scan.nextInt();
			}
		}
		System.out.println("The matrix is: ");
		for (int i = 0; i < m; i++) 
		{
			for (int j = 0; j < n; j++) 
			{
				System.out.print("\t" + a[i][j]);
			}
			System.out.println();
		}
		/*
		Second Matrix
		*/
		System.out.println("Enter of rows and columns in the second matrix: ");
		System.out.print("Rows: ");
		int p = scan.nextInt();
		System.out.print("Cols: ");
		int q = scan.nextInt();
		int b[][] = new int[p][q];
		System.out.println("Enter the elements of the matrix: ");
		for (int i = 0; i < m; i++) 
		{
			for (int j = 0; j < n; j++) 
			{
				b[i][j] = scan.nextInt();
			}
		}
		System.out.println("The matrix is: ");
		for (int i = 0; i < m; i++) 
		{
			for (int j = 0; j < n; j++) 
			{
				System.out.print("\t" + b[i][j]);
			}
			System.out.println();
		}
		if (n != p)
		{
			System.out.println("Matrix Multiplication not possible!");
			System.exit(0);
		}
		System.out.println("The result of the Multiplication is: ");
		int multi[][] = new int[m][q];
		for (int i = 0; i < m; i++) 
		{
			for (int j = 0; j < n; j++) 
			{
				int sum = 0;
				for (int k = 0; k < q; k++) 
				{
					sum += a[i][k] * b[k][j];
				}
				multi[i][j] = sum;
			}
		}
		System.out.println("Resultant matrix is: ");
		for (int i = 0; i < m; i++) 
		{
			for (int j = 0; j < q; j++) 
			{
				System.out.print("\t" + multi[i][j]);
			}
			System.out.println();
		}
		scan.close();
	}
}
