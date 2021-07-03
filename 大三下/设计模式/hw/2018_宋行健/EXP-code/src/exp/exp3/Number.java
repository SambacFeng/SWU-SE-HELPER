package exp.exp3;

import javafx.geometry.Point2D;
import javafx.scene.image.Image;

public class Number extends Entity implements Cloneable{
	private int num;
	
	
	public Number() {
		this(null);
	}

	public Number(Image img) {
		this(img, new Point2D(0, 0), 0);
	}

	public Number(Image img, int num) {
		this(img, new Point2D(0, 0), num);
	}
	
	public Number(Image img, Point2D pos, int num) {
		super(img, pos);
		setNum(num);
	}

	// 浅复制
	public Object clone() throws CloneNotSupportedException {
		return super.clone();
	}

	public int getNum() {
		return num;
	}

	public void setNum(int num) {
		this.num = num;
	}
}
