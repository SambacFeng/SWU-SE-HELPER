package exp.exp3;

import javafx.geometry.Point2D;
import javafx.scene.image.Image;

public abstract class Entity implements Cloneable{
	private Image currentLook;
	private Point2D position;
	private double width;
	private double height;
	
	public Entity() {
		this(null);
	}
	
	public Entity(Image img) {
		this(img, new Point2D(0, 0));
	}
	
	public Object clone() throws CloneNotSupportedException {
		Entity e = (Entity) super.clone();
		e.setPosition(new Point2D(this.getPosition().getX(), this.getPosition().getY()));
		return e;
	}
	
	public Entity(Image img, Point2D pos) {
		currentLook = img;
		position = pos;
		if(img != null) {
			width = img.getWidth();
			height = img.getHeight();
		}
	}
	
	// 判断两个实体是否相交
	public boolean isOverlap(Entity e) {
		Point2D p1 = getPosition();
		Point2D p2 = e.getPosition();
		if(p1.getX() + this.getWidth() > p2.getX() 
				&& p2.getX() + e.getWidth() > p1.getX() 
				&& p1.getY() + this.getHeight() > p2.getY() 
				&& p2.getY() + e.getHeight() > p1.getY()) {
			return true;
		}
		return false;
	}
	
	public Image getCurrentLook() {
		return currentLook;
	}
	public void setCurrentLook(Image currentLook) {
		this.currentLook = currentLook;
	}
	public Point2D getPosition() {
		return position;
	}
	public void setPosition(Point2D position) {
		this.position = position;
	}

	public double getHeight() {
		return height;
	}

	public void setHeight(double height) {
		this.height = height;
	}

	public double getWidth() {
		return width;
	}

	public void setWidth(double width) {
		this.width = width;
	}
}
