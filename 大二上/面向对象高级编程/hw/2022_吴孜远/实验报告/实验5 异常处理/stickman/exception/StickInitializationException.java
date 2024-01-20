package exp5.stickman.exception;

public class StickInitializationException extends RuntimeException{

	private static final long serialVersionUID = -6026447143285749889L;

	public StickInitializationException(){}
	public StickInitializationException(String msg){
		super(msg);
	}
}

