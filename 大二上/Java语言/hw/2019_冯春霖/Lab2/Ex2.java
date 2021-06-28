package week2;
import java.util.Scanner;
public class Ex2 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.println("***************Game Start!***************");
		int playerWin = 0;
		int compWin = 0;
		String[] types = {"scissor", "rock", "paper"};
		while(playerWin < 2 && compWin < 2)
		{
			int comp = (int)(Math.random() * 3);
			System.out.print("scissor (0), rock (1), paper (2):");
			int player = input.nextInt();
			if (player < 0 || player > 2)
			{
				System.out.println("illegal input, try again!");
				continue;
			}
			if (player == comp)
				System.out.printf("The computer is %s. You are %s.(computer:%d, you:%d)\n", types[comp], types[player], compWin, playerWin);
			else if (player == 0 && comp == 2 || player == 1 && comp == 0 || player == 2 && comp == 1)
			{
				playerWin++;
				System.out.printf("The computer is %s. You are %s.(computer:%d, you:%d)\n", types[comp], types[player], compWin, playerWin);
			}
			else
			{
				compWin++;
				System.out.printf("The computer is %s. You are %s.(computer:%d, you:%d)\n", types[comp], types[player], compWin, playerWin);
			}
				
		}
		if (playerWin == 2)
			System.out.println("You Win!");
		else
			System.out.println("Computer Win!");
		input.close();

	}

}
