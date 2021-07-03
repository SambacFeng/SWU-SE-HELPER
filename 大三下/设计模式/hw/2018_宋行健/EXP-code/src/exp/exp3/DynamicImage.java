package exp.exp3;

import java.util.ArrayList;
import java.util.List;

import javafx.scene.image.Image;

public class DynamicImage implements Cloneable{
	private final List<Image> images;
	private int index = 0;  //游标
	private boolean repeated = false; //是否循环播放
	
	public DynamicImage() {
		this(new ArrayList<Image>(), false);
	}
	
	public DynamicImage(List<Image> imgs) {
		this(imgs, false);
	}
	
	public DynamicImage(List<Image> imgs, boolean repeated) {
		this.images = imgs;
		this.repeated = repeated;
	}

	// 浅复制
	public Object clone() throws CloneNotSupportedException {
		return super.clone();
	}
	
	public Image getImage() {
		return getImage(index);
	}
	
	public Image getImage(int index) {
		return images.get(index);
	}
	
	public void add(Image img) {
		images.add(img);
	}
	
	public void nextFrame() {
		index = (index + 1) % images.size();
	}
	
	public void reset() {
		index = 0;
	}

	public int getIndex() {
		return index;
	}

	public void setIndex(int index) {
		this.index = index;
	}
	
	public int numOfImages(){
		return images.size();
	}

	public boolean isRepeated() {
		return repeated;
	}

	public void setRepeated(boolean repeated) {
		this.repeated = repeated;
	}
}
