import java.util.*;

public class DeterminantofMatrix {
	static int determinant(int a[][])
	{
		int result = 0;
		if (a.length == 1) 
		{
			result = a[0][0];
		} 
		else if (a.length == 2) 
		{
			result = a[0][0] * a[1][1] - a[1][0] * a[0][1];
		} 
		else 
		{
			for (int i = 0; i < a[0].length; i++) 
			{
				int temp[][] = new int[a.length - 1][a[0].length - 1];

				for (int j = 1; j < a.length; j++) 
				{
					for (int k = 0; k < a[0].length; k++) 
					{

						if (k < i) 
						{
							temp[j - 1][k] = a[j][k];
						} 
						else if (k > i) 
						{
							temp[j - 1][k - 1] = a[j][k];
						}
					}
				}
				result += a[0][i] * Math.pow(-1, (int) i) * determinant(temp);
			}
		}
		return result;
	}
	public static void main(String[] args) {
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
		for (int i = 0; i < m; i++) 
		{
			for (int j = 0; j < n; j++) 
			{
				System.out.print("\t" + a[i][j]);
			}
			System.out.println();
		}
		System.out.println("Determinant is: " + determinant(a));
		scan.close();
	}
}