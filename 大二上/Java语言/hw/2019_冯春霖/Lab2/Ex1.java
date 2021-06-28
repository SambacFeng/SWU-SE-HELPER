package week2;
import java.util.Scanner;
public class Ex1 {
	
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		double radius = 10.0;
		System.out.println("Please input x and y");
		double x = input.nextDouble();
		double y = input.nextDouble();
		double dist = Math.sqrt(x * x + y * y);
		if (dist > radius)
			System.out.printf("Point(%4.1f, %4.1f) is outside the circle.\n", x, y);
		else if (dist < radius)
			System.out.printf("Point(%4.1f, %4.1f) is in the circle.\n", x, y);
		else
			System.out.printf("Point(%4.1f, %4.1f) is on the circle.\n", x, y);
		input.close();
		
	}
	
}
