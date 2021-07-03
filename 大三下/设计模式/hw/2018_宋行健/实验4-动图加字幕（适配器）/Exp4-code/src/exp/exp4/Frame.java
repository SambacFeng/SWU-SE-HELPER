package exp.exp4;

import javafx.scene.image.Image;

public class Frame {
    private Image image;
    private int delay;  // ∫¡√Î
    private double width;   // GiføÌ∂»
    private double height;   // Gif∏ﬂ∂»

    public Frame(Image img, int d) {
        image = img;
        delay = d;
        width = img.getWidth();
        height = img.getHeight();
    }

    public Image getImage() {
        return image;
    }

    public void setImage(Image image) {
        this.image = image;
    }

    public double getWidth() {
        return width;
    }

    public void setWidth(double width) {
        this.width = width;
    }

    public void setHeight(double height) {
        this.height = height;
    }

    public double getHeight() {
        return height;
    }

    public int getDelay() {
        return delay;
    }

    public void setDelay(int delay) {
        this.delay = delay;
    }
}
