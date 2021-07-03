package exp.exp5;

import javafx.geometry.Point2D;
import javafx.geometry.Rectangle2D;
import javafx.scene.image.Image;

public abstract class Entity {
    private Image look;
    private Rectangle2D frame;    // 边界
    private Point2D speed;    // 移动速度

    public Entity() {
        this(ImageTool.generateImage(1, 1, 0, 0, 0, 0), new Rectangle2D(0, 0, 0, 0));
    }

    public Entity(Rectangle2D frame) {
        this(ImageTool.generateImage((int) frame.getWidth(), (int) frame.getHeight(), 0, 0, 0, 0), frame);
    }

    public Entity(Image img) {
        this(img, new Rectangle2D(0, 0, img.getWidth(), img.getHeight()));
    }

    public Entity(Image look, Rectangle2D frame) {
        this.look = look;
        this.frame = frame;
        this.speed = new Point2D(0.0, 0.0);
    }

    public Rectangle2D getFrame() {
        return frame;
    }

    public void setFrame(Rectangle2D frame) {
        this.frame = frame;
    }

    public Image getLook() {
        return look;
    }

    public void setLook(Image look) {
        this.look = look;
    }

    public Point2D getSpeed() {
        return speed;
    }

    public void setSpeed(Point2D speed) {
        this.speed = speed;
    }
}
