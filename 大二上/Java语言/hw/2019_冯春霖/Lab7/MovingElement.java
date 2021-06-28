package week16;

import javafx.scene.image.Image;

public class MovingElement extends Element {
	protected MovingElement(Image img) {
		super(img);
	}
	public void left() {
		this.setX(this.getX() - MapPane.CELL_SIZE);
	}
	
	public void right() {
		this.setX(this.getX() + MapPane.CELL_SIZE);
	}
	
	public void up() {
		this.setY(this.getY() - MapPane.CELL_SIZE);
	}
	
	public void down() {
		this.setY(this.getY() + MapPane.CELL_SIZE);
	}

}
