package exp.exp4;

import java.awt.image.BufferedImage;
import javafx.embed.swing.SwingFXUtils;

public class GIFReader implements IGIFReader {
	private GifDecoder gdc;
	
	@Override
	public Frame[] read(String gifPath) {
		gdc = new GifDecoder();
		gdc.read(gifPath);
		int n = gdc.getFrameCount();
		Frame[] frames = new Frame[n];
		for (int i = 0; i < n; i++) {
			BufferedImage img = gdc.getFrame(i);
			int delay = gdc.getDelay(i);
			frames[i] = new Frame(SwingFXUtils.toFXImage(img, null), delay);
		}
		return frames;
	}
	
	public GifDecoder getGdc() {
		return gdc;
	}

	public void setGdc(GifDecoder gdc) {
		this.gdc = gdc;
	}

}
