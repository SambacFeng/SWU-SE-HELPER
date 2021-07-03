package exp.exp5;

import javafx.scene.image.Image;

public class Protection extends LookDecorator {
	private DynamicImage looks;

	public Protection(DynamicImage looks) {
		super();
		this.looks = looks;
	}

	@Override
	public Entity entityToDraw() {
		Entity e = super.entityToDraw();
		return e;
	}

	public DynamicImage getLooks() {
		return looks;
	}

	public void setLooks(DynamicImage looks) {
		this.looks = looks;
	}

	@Override
	public Image getImageForMerge() {
		looks.nextFrame();
		return looks.getImage();
	}

}
