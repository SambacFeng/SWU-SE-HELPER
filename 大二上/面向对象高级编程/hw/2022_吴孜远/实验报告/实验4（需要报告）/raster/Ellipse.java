package raster;

public class Ellipse extends Shape{
	private int centerX,centerY, semiMajorAxis, semiMinorAxis;
	
	public Ellipse(int x, int y, int a, int b) {
		centerX = x;
		centerY = y;
		semiMajorAxis = a;
		semiMinorAxis = b;
	}
	
	@Override
	public Raster raster() {
		int minx = centerX - semiMajorAxis;
		int miny = centerY - semiMinorAxis;
		int maxx = centerX + semiMajorAxis;
		int maxy = centerY + semiMinorAxis;
		int rasterW = maxx - minx + 1;
		int rasterH = maxy - miny + 1;
		Raster r = new Raster(minx, miny, rasterW, rasterH);
		for(int x = minx; x < minx + rasterW; x++) {
			for(int y = miny; y < miny + rasterH; y++) {
				if(isPointInsideEllipse(x, y)) {
					r.setValue(x, y, 1);
				}
			}
		}
		return r;
	}
	
	//用椭圆的基本公式判断是否在椭圆内
	public boolean isPointInsideEllipse(int x, int y) {
        double value = Math.pow((double)(x - centerX) / (double) semiMajorAxis, 2) +
                       Math.pow((double)(y - centerY) / (double) semiMinorAxis, 2);
        return value <= 1;
    }

}