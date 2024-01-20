package exp6.biz;

public class Move implements Command{

	final private Ball ball; // 每个命令针对一个对象
	private int targetX, targetY;
	
	public Move(Ball ball, int x, int y) {
		this.ball = ball;
		targetX = x;
		targetY = y;
	}
	
	//？？？
	@Override
	public boolean equals(Object w) {
		return ball == ((Move)w).ball; //所操控的ball相同则Move命令就equals
	}
	
	//何时完成动作
	public boolean done() {
		return ball.getX() == targetX && ball.getY() == targetY;
	}
	
	@Override
	public void execute() {
		//前后计算步长dx，dy，这里为1或-1，每一次execute前进一个步长
		if(ball.getX() != targetX) {
			int dx = (targetX - ball.getX()) / Math.abs(targetX - ball.getX());
			ball.setX(ball.getX() + dx);
		}else if(ball.getY() != targetY){
			int dy = (targetY - ball.getY()) / Math.abs(targetY - ball.getY());
			ball.setY(ball.getY() + dy);
		}
		ball.setState((ball.getState() + 1) % 2); //对2取余保证状态值是0 or 1
	}

}
