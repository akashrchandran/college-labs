/**
 * @author Akash R Chandran
 * @email chandranrakash@gmail.com
 * @create date 2022-02-13 19:45:23
 * @modify date 2022-04-25 22:22:27
 * @desc To find determinant of matrix
 */

import java.util.*;

public class DeterminantofMatrix3x3 
{
	public static void main(String[] args) 
	{
		Scanner scan = new Scanner(System.in);
		System.out.println("Enter of rows and columns in matrix: ");
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
		System.out.println("Enter the elements of the matrix: ");
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				System.out.print("\t" + a[i][j]);
			}
			System.out.println();
		}
		int result = 0;
		if (a.length == 1) 
		{
			result = a[0][0];
		} 
		else if (a.length == 2) 
		{
			result = a[0][0] * a[1][1] - a[1][0] * a[0][1];
		} 
		else if (a.length == 3) 
		{
			result += a[0][0] * ((a[1][1] * a[2][2]) - (a[2][1] * a[1][2]));
			result -= a[0][1] * ((a[1][0] * a[2][2]) - (a[2][0] * a[1][2]));
			result += a[0][2] * ((a[1][0] * a[2][1]) - (a[2][0] * a[1][1]));
		} 
		else 
		{
			System.out.println("This is out of my scope, do it by hand!");
		}
		System.out.println("Determinant is: " + result);
		scan.close();
	}
}