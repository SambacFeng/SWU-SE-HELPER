package week9;

public class Board {
	public final static int SIZE = 15;
	private Stone[][] board;
	private int remain;
	private int whichColorToPlay;
	private int winColor = -1;
	
	public Board() 
	{
		board = new Stone[SIZE][SIZE];
		remain = SIZE * SIZE;
		whichColorToPlay = (int)(Math.random() * 2);
	}
	
	public void printBoard()
	{  
		System.out.println("    1  2  3  4  5  6  7  8  9 10 11 12 13 14 15");
		for(int i = 0; i < 15; i++)
		{
			System.out.printf("%2d", i + 1);
			for (int j = 0; j < 15; j++)
				if (board[i][j] != null)
					System.out.printf("%3c", board[i][j].getShape());
				else
					System.out.print("  +");
			System.out.println();
		}
	}
	
	public boolean putAStone(int row, int column, Stone stone) {
		if (row < 0 || row > SIZE - 1 || column < 0 || column > SIZE - 1 || board[row][column] != null) 
		{
			return false;
		}
			else 
		{
			board[row][column] = stone;
			remain--;
			whichColorToPlay = stone.getColor() == Stone.WHITE ? Stone.BLACK:Stone.WHITE;
			winColor = judge(row, column);
			return true;
		}
	}
	
	public int judge(int row, int column)
	{
		String kernel = new String(new char[5]).replace("\0", String.valueOf(board[row][column].getColor()));
		
		StringBuffer lineX = new StringBuffer();
		for(int i = 0; i < SIZE; i++) 
			if(board[row][i] != null) 
				lineX.append(board[row][i].getColor());
			else 
				lineX.append("N");
		if(lineX.indexOf(kernel) >= 0)
			return board[row][column].getColor();
		
		StringBuffer lineY = new StringBuffer();
		for(int i = 0; i < SIZE; i++)
			if(board[i][column] != null)
				lineY.append(board[i][column].getColor());
			else
				lineY.append("N");
		if(lineY.indexOf(kernel) >= 0)
			return board[row][column].getColor();
		
		StringBuffer lineDiagA = new StringBuffer();
		if(row >= column)
			for (int i = row - column, j = 0; i < SIZE; i++, j++)
				if(board[i][j] != null)
					lineDiagA.append(board[i][j].getColor());
				else
					lineDiagA.append("N");
		else
			for (int i = 0, j = column - row; j < SIZE; i++, j++)
				if(board[i][j] != null)
					lineDiagA.append(board[i][j].getColor());
				else
					lineDiagA.append("N");	
		if(lineDiagA.indexOf(kernel) >= 0)
			return board[row][column].getColor();
		
		StringBuffer lineDiagB = new StringBuffer();
		if(row + column < SIZE - 1)
			for (int i = 0, j = row + column; i < row + column + 1; i++, j--)
				if(board[i][j] != null)
					lineDiagB.append(board[i][j].getColor());
				else
					lineDiagB.append("N");
		else
			for (int i = row + column - SIZE + 1, j = SIZE - 1; i < SIZE; i++, j--)
				if(board[i][j] != null)
					lineDiagB.append(board[i][j].getColor());
				else
					lineDiagB.append("N");
		if(lineDiagB.indexOf(kernel) >= 0)
			return board[row][column].getColor();
	
		return -1;
	}

	public int getRemain() 
	{
		return remain;
	}
	
	public void setRemain(int remain) 
	{
		this.remain = remain;
	}
	
	public int getWhichColorToPlay() 
	{
		return whichColorToPlay;
	}
	
	public void setWhichColorToPlay(int whichColorToPlay) 
	{
		this.whichColorToPlay = whichColorToPlay;
	}
	
	public int getWinColor() 
	{
		return winColor;
	}
	
	public void setWinColor(int winColor) 
	{
		this.winColor = winColor;
	}

}
