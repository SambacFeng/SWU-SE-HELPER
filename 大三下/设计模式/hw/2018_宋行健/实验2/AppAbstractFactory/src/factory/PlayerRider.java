package factory;

import javafx.geometry.Point2D;
import javafx.scene.image.Image;

public class PlayerRider extends Rider {
	public PlayerRider(Image[] imgs, Point2D pos) {
		super(imgs, pos);
	}

	@Override
	public void move() {
		setCurrentIndex((getCurrentIndex() + 1) % getImage().length);
		if(getPosition().getX() >= 800) {
			setPosition(getPosition().add(-600, 0));
		}else {
			setPosition(getPosition().add(10, 0));
		}
	}
}
