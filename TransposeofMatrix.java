import java.util.*;

public class TransposeofMatrix {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		System.out.println("Enter the no. of rows and columns: ");
		System.out.print("Rows: ");
		int m = scan.nextInt();
		System.out.print("Cols: ");
		int n = scan.nextInt();
		int a[][] = new int[m][n];
		System.out.println("Enter the elemnets of the matrix: ");
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				a[i][j] = scan.nextInt();
			}
		}
		scan.close();
		System.out.println("The matrix is: ");
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				System.out.print("\t"+ a[i][j]);
			}
			System.out.println();
		}
		System.out.println("The Transpose of the matrix is: ");
		int b[][] = new int[n][m];
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				b[j][i] = a[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				System.out.print("\t"+ b[i][j]);
			}
			System.out.println();
		}
	}
}
