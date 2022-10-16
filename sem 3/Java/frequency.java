package lab;
import java.util.Scanner;
public class frequency {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter the String: ");
        String word = scan.nextLine();
        System.out.print("Enter the key: ");
        char key = scan.nextLine().charAt(0);
        scan.close();
        int count = 0;
        for (int i = 0; i < word.length(); i++) {
            char letter = word.charAt(i);
            if (letter == key)
            {
                count++;
            }
        }
        System.out.println(String.format("The frequency count of %s in word %s is: ", key, word) + count);
    }
}
