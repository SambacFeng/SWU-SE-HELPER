package week9;

import java.util.Scanner;

public class Player {
	private String name;
	private int color;
	
	public Player(String name, int color) 
	{
		this.setName(name);
		this.setColor(color);
	}

	public String getName() 
	{
		return name;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public int getColor() {
		return color;
	}
	
	public void setColor(int color) {
		this.color = color;
	}
	
	public void play(Board board, Scanner input) 
	{
		System.out.printf("Player %s[%s] put a stone at:", this.getName(), Stone.colorToString(color));
		int row = input.nextInt() - 1;
		int column = input.nextInt() - 1;
		boolean success = board.putAStone(row, column, new Stone(color));
		if(!success) 
		{
			System.out.println("Illegal Input");
			this.play(board, input);
		}
	}


}
