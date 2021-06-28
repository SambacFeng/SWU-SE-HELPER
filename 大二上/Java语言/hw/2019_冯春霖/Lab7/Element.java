package week16;

import javafx.scene.image.Image;
import javafx.scene.image.ImageView;

public abstract class Element extends ImageView {
	public final static int MAN = 0;
	public final static int BOX = 1;
	public final static int WALL = 2;
	public final static int TARGET = 3;
	public final static int BACKGROUND = 4;
	
	protected Element(Image img) {
		super(img);
		
		this.setFitHeight(MapPane.CELL_SIZE);
		this.setFitWidth(MapPane.CELL_SIZE);
	}

}
