package exp5.stickman.exception;

public class JointNullException extends Exception{

	private static final long serialVersionUID = 2L;
	public JointNullException(){}
	public JointNullException(String msg){
		super(msg);
	}
}