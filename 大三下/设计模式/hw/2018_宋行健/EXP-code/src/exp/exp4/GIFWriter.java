package exp.exp4;

import javafx.embed.swing.SwingFXUtils;

public class GIFWriter implements IGIFWriter{
	private AnimatedGifEncoder gifEncoder;

	@Override
	public void write(Frame[] frames, String targetFileName) {
		gifEncoder = new AnimatedGifEncoder();
		gifEncoder.start(targetFileName);
		gifEncoder.setRepeat(0);
		for(Frame f:frames) {
			gifEncoder.setDelay(f.getDelay());
			gifEncoder.addFrame(SwingFXUtils.fromFXImage(f.getImage(), null));
		}
		gifEncoder.finish();
	}

	public AnimatedGifEncoder getGifEncoder() {
		return gifEncoder;
	}

	public void setGifEncoder(AnimatedGifEncoder gifEncoder) {
		this.gifEncoder = gifEncoder;
	}
	
}
