package exp6.biz;

import java.util.Map;
import java.util.HashMap;

public class GameMap {
	private int width, height;
	private Map<Integer, Integer> cells = new HashMap<Integer, Integer>();
	
	public GameMap(int w, int h) {
		width = w;
		height = h;
	}
	
	// 根据坐标计算地址编码，将二维坐标转换为一维值，方便作为cells的key
	public int locationCode(int x, int y) {
		return y * width + x;
	}
	// 设置地块状态值
	public void put(int x, int y, int codeValue) {
		cells.put(locationCode(x, y), codeValue);
	}
	// 获取地块状态值，传入坐标，返回状态
	public int get(int x, int y) {
		Integer lc = locationCode(x, y);
		if(cells.containsKey(lc)) {//map中是否包含key：lc
			return cells.get(lc); //获取key对应的value并返回
		}
		return 0;
	}

	public int getHeight() {
		return height;
	}
	public int getWidth() {
		return width;
	}
}
