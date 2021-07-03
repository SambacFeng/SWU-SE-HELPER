package exp.exp5;

import javafx.geometry.Rectangle2D;
import javafx.scene.SnapshotParameters;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.image.Image;
import javafx.scene.paint.Color;

public abstract class LookDecorator implements ILook{
	private ILook look;
	private int offx;
	private int offy;
	private int width;
	private int height;
	
	public ILook getLook() {
		return look;
	}

	public void setLook(ILook look) {
		this.look = look;
	}

	@Override
	public Entity entityToDraw() {
		Entity e = look.entityToDraw();
		Image img = getImageForMerge();
		
		Rectangle2D r = e.getFrame();	
		Canvas canvas = new Canvas(r.getWidth(), r.getWidth());
		GraphicsContext gc = canvas.getGraphicsContext2D();
		gc.drawImage(e.getLook(), 0, 0);
		gc.drawImage(img, getOffx(), getOffy(), getWidth(), getHeight());
		SnapshotParameters parameters = new SnapshotParameters();
		parameters.setFill(Color.TRANSPARENT);
		e.setLook(canvas.snapshot(parameters, null));
		e.setFrame(new Rectangle2D(0, 0, r.getWidth(), r.getWidth()));
		
		return e;
	}
	
	public abstract Image getImageForMerge();

	public int getOffx() {
		return offx;
	}

	public void setOffx(int offx) {
		this.offx = offx;
	}

	public int getOffy() {
		return offy;
	}

	public void setOffy(int offy) {
		this.offy = offy;
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
}
