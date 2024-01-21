package exp6.biz;

public class Ball {
	private int x, y;
	private int state;

	public Ball(int x, int y) {
		setX(x);
		setY(y);
	}
	
	// 判断是否在矩形范围中，传入矩形的两个对角点坐标判断即可
	public boolean in(int x1, int y1, int x2, int y2) {
		return x <= Math.max(x1, x2) && x >= Math.min(x1, x2) && y <= Math.max(y1, y2) && y >= Math.min(y1, y2);
	}

	public int getX() {
		return x;
	}

	public void setX(int x) {
		this.x = x;
	}

	public int getY() {
		return y;
	}

	public void setY(int y) {
		this.y = y;
	}

	public int getState() {
		return state;
	}

	public void setState(int state) {
		this.state = state;
	}
	
}
