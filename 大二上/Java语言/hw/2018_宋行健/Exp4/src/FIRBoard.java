
public class FIRBoard {

	private int [][] grid;
	public static final int BOARD_SIZE=10;
	public static final int EMPTY =0;
	public static final int WHITE = 1;
	public static final int BLACK = -1;
	private int remain;
	
	private int win;
	public static final int NO_WIN = 0;
	public static final int LENGTH = 5;
	
	private int currentPlayer;
	private int previousPlayer;
	
	private int previousR;
	private int previousC;
	
	
	public FIRBoard(){
		initializeGrid();
	}
	
	public void initializeGrid(){
		grid = new int [10][10];
		currentPlayer = WHITE;
		win = NO_WIN;
		remain = 100;
	}
	
	public void printGrid(){
		System.out.println("  1 2 3 4 5 6 7 8 9 10");
		for(int i=0;i<10;i++){
			System.out.print(i+1);
			System.out.print(" ");
			for(int j=0;j<10;j++){
				if(grid[i][j]==0)
					System.out.print("+ ");				
				else if(grid[i][j]==-1)
					System.out.print("¡ñ ");	
				else
					System.out.print("¡ð ");	
			}
			System.out.println();				
		}
	}
	
	public int whoWin(){
		return win;
	}
	
	public int getRemain(){
		return remain;
	}
	
	public int whoseTurn(){
		return currentPlayer;
	}
	
	public boolean setChessPiece (int row, int col){
		if(grid[row][col]==0)
			return true;
		else return false;
	}
	
	
}
