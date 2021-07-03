package game;

import java.io.IOException;

import javafx.geometry.Point3D;
import javafx.scene.SnapshotParameters;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.image.PixelReader;
import javafx.scene.image.WritableImage;
import javafx.scene.paint.Color;

public class ImageTool {
	public static void main(String[] args) throws IOException {
		ImageTool i = new ImageTool();
		i.displayPath();
	}
	
	public void displayPath() {
		System.out.println(this.getClass().getResource("").getPath());
	}
	
	public static Image clipImage(Image sourceImage, int x, int y, int w, int h) {
		PixelReader pr = sourceImage.getPixelReader();
		return new WritableImage(pr, x, y, w, h);
	}
	
	public static Image scale(Image source, int targetWidth, int targetHeight, boolean preserveRatio) {
	    ImageView imageView = new ImageView(source);
	    imageView.setPreserveRatio(preserveRatio);
	    imageView.setFitWidth(targetWidth);
	    imageView.setFitHeight(targetHeight);
	    SnapshotParameters parameters = new SnapshotParameters();
	    parameters.setFill(Color.TRANSPARENT);
	    return imageView.snapshot(parameters, null);
	}
	
	public static Image rotate(Image source, double angle, Point3D axis) {
		ImageView imageView = new ImageView(source);
	    imageView.setFitWidth(source.getWidth());
	    imageView.setFitHeight(source.getHeight());
	    imageView.setRotate(angle);
	    imageView.setRotationAxis(axis);
		SnapshotParameters parameters = new SnapshotParameters();
		parameters.setFill(Color.TRANSPARENT);
		return imageView.snapshot(parameters, null); 
	}
}
