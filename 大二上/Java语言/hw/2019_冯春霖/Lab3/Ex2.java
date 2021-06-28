package week8;
import java.util.Scanner;
public class Ex2 {

	public static int countRemainNum(int[][] grid) 
	{  
		int remain = 0; 
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			if(grid[i][j]==0)
				remain++;
		}
	}
		return remain; 
	}
	
	public static void printGrid(int[][] grid){ 
		for(int i = 0; i < 9; i++){   
			for(int j = 0; j < 9; j++){ 
				  System.out.print(grid[i][j] + " ");
				  if((j + 1) % 3 == 0)
					  System.out.print("|");
			  }
			  System.out.println();
			  if((i + 1) % 3 == 0)
				  System.out.println("------|------|------|");
		  
			
		}
	}
	
	public static boolean isValid(int r, int c, int n, int[][] grid) { 
		for (int column = 0; column < 9; column++)   
			if (grid[r][column] == n)  
				return false; 
		for(int row=0; row<9; row++)
			if(grid[row][c]==n)
				return false;
		for(int i=3*(r/3);i<3*(r/3)+2;i++)
			for(int j=3*(c/3);j<3*(c/3)+2;j++)
				if(grid[i][j]==n)
					return false;
				return true;
	}
	
	
public static void main(String[] args)
{
	
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
	printGrid(grid);
	//System.out.printf("there are still %d numbers remain",countRemainNum(grid));
	int remain=countRemainNum(grid);
	while(remain>0){
		System.out.print("Enter row, column and number([1-9] [1-9] [1-9]):"); 
		int r = input.nextInt() - 1;   
		int c = input.nextInt() - 1;   
		int n = input.nextInt();   
		
		   if(grid[r][c] != 0){    
			   System.out.println("The cell is not empty!"); 
		   }else{    
			   if(isValid(r,c,n,grid)){
				   grid[r][c] = n;     
				   remain--; 
				   System.out.println("The current state of grid:");     
				   printGrid(grid); 
			   }else{     
				   System.out.println("The number is irrational.");    
				   }   
		   }
	}
	System.out.printf("”Œœ∑Ω· ¯");
	input.close();
}}
