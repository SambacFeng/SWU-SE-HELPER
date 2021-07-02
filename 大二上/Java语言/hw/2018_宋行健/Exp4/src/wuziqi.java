
public class wuziqi {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		while(board.whoWin()== FIRBoard.NO_WIN && board.getRemain()>0){
			if(board.getCurrentPlayer()==player1.getType()){
				player1.putAPiece(board);
			}else{
				player2.putAPiece(board);
			}
		}
		board.printGrid();
		board.judge();
		
	}

}
