package lab;

import java.util.Scanner;

public class palindrome {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter the String to check pallindrome: ");
        String word = scan.nextLine();
        scan.close();
        String reverse = new String();
        for (int i = word.length() - 1; i >= 0; i--) {
            reverse = reverse + word.charAt(i);
        }
        if (word.equalsIgnoreCase(reverse))
        {
            System.out.println(String.format("The given string %s is a palindrome", word));
        }
        else
        {
            System.out.println(String.format("The given string %s is NOT a palindrome", word));
        }
    }
}
