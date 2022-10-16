package lab;

import java.util.Scanner;

class Employee {
    protected String name;
    protected int age;
    protected String address;
    protected int phone;
    protected int salary;
    void printSalary() {
        System.out.println("Salary is: " + salary);
    }

}

class Officer extends Employee {
    String specialization;
    public Officer() {
        Scanner scan = new Scanner(System.in);
        System.out.print("Name: ");
        name = scan.nextLine();
        System.out.print("Address: ");
        address = scan.nextLine();
        System.out.print("Specialization: ");
        specialization = scan.nextLine();
        System.out.print("Age: ");
        age = scan.nextInt();
        System.out.print("Phone: ");
        phone = scan.nextInt();
        System.out.print("Salary: ");
        salary = scan.nextInt();
        scan.close();
    }
}

class Manager extends Employee {
    String deartment;
    public Manager() {
        Scanner scan = new Scanner(System.in);
        System.out.print("Name: ");
        name = scan.nextLine();
        System.out.print("Address: ");
        address = scan.nextLine();
        System.out.print("Age: ");
        age = scan.nextInt();
        System.out.print("Phone: ");
        phone = scan.nextInt();
        System.out.print("Salary: ");
        salary = scan.nextInt();
        System.out.print("Specialization: ");
        deartment = scan.nextLine();
        scan.close();
    }
}

public class Employee_manager{
    public static void main(String[] args) {
        Officer f = new Officer();
        System.out.println(f.specialization);
        f.printSalary();
    }
}
