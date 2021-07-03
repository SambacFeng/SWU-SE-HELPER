package factory;

import javafx.geometry.Point2D;
import javafx.scene.image.Image;

public abstract class Rider {
	private Image[] image;
	private Point2D position;
	private int currentIndex;
	
	
	public Rider(Image[] imgs, Point2D pos) {
		setPosition(pos);
		setImage(imgs);
		setCurrentIndex(0);
	}
	
	public abstract void move();
	
	public Image getCurrentImage() {
		return image[getCurrentIndex()];
	}
	
	public Rider() {
		
	}
	
	
	public Point2D getPosition() {
		return position;
	}
	public void setPosition(Point2D position) {
		this.position = position;
	}

	public Image[] getImage() {
		return image;
	}

	public void setImage(Image[] image) {
		this.image = image;
	}

	public int getCurrentIndex() {
		return currentIndex;
	}

	public void setCurrentIndex(int currentIndex) {
		this.currentIndex = currentIndex;
	}
}
