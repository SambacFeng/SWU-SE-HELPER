package exp.exp3;

import javafx.geometry.Point2D;
import javafx.scene.image.Image;

public class Map extends Entity{
	private double horizonY;
	

	public Map() {
		this(null);
	}
	
	public Map(Image img) {
		this(img, new Point2D(0, 0));
	}
	
	public Map(Image img, Point2D pos) {
		super(img, pos);
	}

	public double getHorizonY() {
		return horizonY;
	}

	public void setHorizonY(double horizonY) {
		this.horizonY = horizonY;
	}
}
