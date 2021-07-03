package exp.exp5;

import javafx.scene.image.Image;

public class Level extends LookDecorator{
	private int level;
	private Image levelImg;

	public Level(Image levelImg) {
		super();
		this.levelImg = levelImg;
	}

	@Override
	public Entity entityToDraw() {
		Entity e = super.entityToDraw();
		return e;
	}

	public int getLevel() {
		return level;
	}

	public void setLevel(int level) {
		this.level = level;
	}
	
	public Image getLevelImg() {
		return levelImg;
	}

	public void setLevelImg(Image levelImg) {
		this.levelImg = levelImg;
	}

	@Override
	public Image getImageForMerge() {
		return levelImg;
	}


}
