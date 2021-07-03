package exp.exp5;

import java.io.IOException;
import java.util.Arrays;

import javafx.geometry.Point3D;
import javafx.scene.SnapshotParameters;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.image.PixelFormat;
import javafx.scene.image.PixelReader;
import javafx.scene.image.PixelWriter;
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
	
	public static Image generateImage(int width, int height, double red, double green, double blue, double opacity) {
	    WritableImage img = new WritableImage(width, height);
	    PixelWriter pw = img.getPixelWriter();

	    // Should really verify 0.0 <= red, green, blue, opacity <= 1.0        
	    int alpha = (int) (opacity * 255) ;
	    int r = (int) (red * 255) ;
	    int g = (int) (green * 255) ;
	    int b = (int) (blue * 255) ;

	    int pixel = (alpha << 24) | (r << 16) | (g << 8) | b ;
	    int[] pixels = new int[width * height];
	    Arrays.fill(pixels, pixel);

	    pw.setPixels(0, 0, width, height, PixelFormat.getIntArgbInstance(), pixels, 0, width);
	    return img ;
	}
}
