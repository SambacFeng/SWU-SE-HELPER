package raster;

public class Circle extends Shape{
	public int centerX,centerY, radius;
	
	public Circle(int x, int y, int r) {
		centerX = x;
		centerY = y;
		radius = r;
	}
	
	@Override
	public Raster raster() {
		int minx = centerX - radius;
		int miny = centerY - radius;
		int maxx = centerX + radius;
		int maxy = centerY + radius;
		int rasterW = maxx - minx + 1;
		int rasterH = maxy - miny + 1;
		Raster r = new Raster(minx, miny, rasterW, rasterH);
		for(int x = minx; x < minx + rasterW; x++) {
			for(int y = miny; y < miny + rasterH; y++) {
				double dis = Math.sqrt(Math.pow(x - centerX, 2) + Math.pow(y - centerY, 2));
				if(dis <= radius) {
					r.setValue(x, y, 1);
				}
			}
		}
		return r;
	}

}
