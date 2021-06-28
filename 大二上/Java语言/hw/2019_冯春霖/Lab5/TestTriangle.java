package week12;

import java.util.Scanner;

public class TestTriangle {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		double a = 1.0, b = 1.0, c = 1.0;
		System.out.print("Please input a: ");
		a = input.nextDouble();
		System.out.print("Please input b: ");
		b = input.nextDouble();
		System.out.print("Please input c: ");
		c = input.nextDouble();
		try {
			Triangle tri = new Triangle(a, b, c);
			System.out.println(tri.toString());
		} catch (Exception e) {
			e.printStackTrace();
		}
		input.close();
	}

}
