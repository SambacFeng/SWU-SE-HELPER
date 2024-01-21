package exp6.biz;

public class ViewArea {
	private int startX, startY;
	private int width, height;
	private GameMap target;
	
	//构造函数
	public ViewArea(int x, int y, int w, int h) {
		update(x, y);
		setWidth(w);
		setHeight(h);
	}
	
	//更新起始坐标值
	public void update(int x, int y) {
		setStartX(x);
		setStartY(y);
	}

	// 视区中的第i个要素代码
	public int getCode(int x, int y) {
		return target.get(startX + x, startY + y);//要先将视野坐标转化为地图坐标
	}
	
	//视野size
	public int size() {
		return width * height;
	}
	
	// 移动可视区域
	public void move(int dx, int dy) {
		int newX = startX + dx > 0 ? startX + dx : 0;
		int newY = startY + dy > 0 ? startY + dy : 0;
		newX = newX + width <= target.getWidth() ? newX : target.getWidth() - width;
		newY = newY + height <= target.getHeight() ? newY : target.getHeight() - height;
		update(newX, newY);
	}

	public GameMap getTarget() {
		return target;
	}

	public void setTarget(GameMap target) {
		this.target = target;
	}

	public int getWidth() {
		return width;
	}

	public void setWidth(int width) {
		this.width = width;
	}

	public int getHeight() {
		return height;
	}

	public void setHeight(int height) {
		this.height = height;
	}
	
	public int getStartX() {
		return startX;
	}

	public void setStartX(int startX) {
		this.startX = startX;
	}

	public int getStartY() {
		return startY;
	}

	public void setStartY(int startY) {
		this.startY = startY;
	}
}
