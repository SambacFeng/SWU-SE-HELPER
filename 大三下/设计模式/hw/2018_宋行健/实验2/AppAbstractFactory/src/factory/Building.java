package factory;

import javafx.geometry.Point2D;
import javafx.scene.image.Image;

public abstract class Building {
	private Image image;
	private Point2D position;
	
	public Building(Image img, Point2D pos) {
		position = pos;
		image = img;
	}
	
	public Building() {}
	
	public Image getImage() {
		return image;
	}
	public void setImage(Image image) {
		this.image = image;
	}
	public Point2D getPosition() {
		return position;
	}
	public void setPosition(Point2D position) {
		this.position = position;
	}
}
