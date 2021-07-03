package exp.exp5;


import javafx.geometry.Rectangle2D;
import javafx.scene.SnapshotParameters;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.paint.Color;

public class Player extends Entity implements ILook{

	public Player(Rectangle2D r) {
		super(r);
	}

	@Override
	public Entity entityToDraw() {
		Rectangle2D r = getFrame();
		Canvas canvas = new Canvas(r.getWidth(), r.getWidth());
		GraphicsContext gc = canvas.getGraphicsContext2D();
		gc.clearRect(0, 0, r.getWidth(), r.getHeight());
		SnapshotParameters parameters = new SnapshotParameters();
		parameters.setFill(Color.TRANSPARENT);
		setLook(canvas.snapshot(parameters, null));
		return this;
	}
}
