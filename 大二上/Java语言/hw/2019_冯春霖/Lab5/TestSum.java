package week12;

import java.util.InputMismatchException;
import java.util.Scanner;

public class TestSum {

	public static void main(String[] args) {
		sumTwoIntegers();

	}
	
	private static void sumTwoIntegers()
	{
		Scanner input = null;
		try 
		{
			input = new Scanner(System.in);
			System.out.print("Please input a: ");
			int a = input.nextInt();
			System.out.print("Please input b: ");
			int b = input.nextInt();
			System.out.printf("%d + %d = %d", a, b, a + b);
		}
		catch(InputMismatchException e)
		{
			System.out.println("Input does not match the integer type, please enter again!");
			sumTwoIntegers();
		}
		finally
		{
			input.close();
		}
	}

}
