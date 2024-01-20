package exp5.stickman.exception;

public class StickmanCompleteException extends RuntimeException{
	private static final long serialVersionUID = 1L;
	public StickmanCompleteException(){}
	public StickmanCompleteException(String msg){
		super(msg);
	}
}
