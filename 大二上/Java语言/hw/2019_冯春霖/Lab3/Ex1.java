package week8;
import java.util.Scanner;

public class Ex1 {
	
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int[][] grid = {{5,3,0,0,7,0,0,0,0},
						{6,0,0,1,9,5,0,0,0},
						{0,9,8,0,0,0,0,6,0},
						{8,0,0,0,6,0,0,0,3},
						{4,0,0,8,0,3,0,0,1},
						{7,0,0,0,2,0,0,0,6},
						{0,6,0,0,0,0,0,0,0},
						{0,0,0,4,1,9,0,0,5},
						{0,0,0,0,8,0,0,7,9}};
		System.out.println("******Game Start!******");
		print(grid);
		while(countRemain(grid) != 0)
		{
			System.out.print("Enter row, column and number([1-9] [1-9] [1-9]):");
			int row = input.nextInt();
			int col = input.nextInt();
			int num = input.nextInt();
			if (isValid(grid, row - 1, col - 1, num))
				grid[row - 1][col - 1] = num;
			print(grid);
		}
		System.out.println("You win!");
		input.close();
	}
	
	public static void print(int grid[][])
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				System.out.printf(" %d", grid[i][j]);
				if (j == 2 || j ==5)
					System.out.print(" |");
			}
			System.out.println();
			if (i == 2 || i == 5)
				printRowDivider();
		}
	}
	
	public static void printRowDivider()
	{
		System.out.println("-------|-------|-------");
	}
	
	public static boolean isValid(int grid[][], int _row, int _col, int _num)
	{
		if (_num < 1 || _num > 9 || _row < 0 || _row > 8 || _col < 0 || _col > 8)
		{
			System.out.println("Invalid number, try again");
			return false;
		}
		if (grid[_row][_col] != 0)
		{
			System.out.println("The cell is not empty, try again");
			return false;
		}
		for (int i = 0; i < 9; i++)
			if (grid[i][_col] == _num)
			{
				System.out.println("There is same number in this column, try again");
				return false;
			}
		for (int j = 0; j < 9; j++)
			if (grid[_row][j] == _num)
			{
				System.out.println("There is same number in this row, try again");
				return false;
			}
		for (int i = _row - _row % 3; i < _row - _row % 3 + 3; i++)
			for (int j = _col - _col % 3; j < _col - _col % 3 + 3; j++)
				if (grid[i][j] == _num)
				{
					System.out.println("There is same number in this block, try again");
					return false;
				}
		return true;
	}
	
	public static int countRemain(int[][] grid)
	{
		int count = 0;
		for (int i = 0; i < 9; i++)
			for(int j = 0; j < 9; j++)
				if (grid[i][j] == 0)
					count++;
		return count;
	}
	
}
