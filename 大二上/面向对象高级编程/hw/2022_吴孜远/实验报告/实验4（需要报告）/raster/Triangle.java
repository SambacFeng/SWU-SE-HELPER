package raster;

public class Triangle extends Shape{
	private int point1X, point1Y, point2X, point2Y, point3X, point3Y;
	
	public Triangle(int p1X, int p1Y, 
			int p2X, int p2Y, 
			int p3X, int p3Y) {
		setPoint1X(p1X);
		setPoint1Y(p1Y);
		setPoint2X(p2X);
		setPoint2Y(p2Y);
		setPoint3X(p3X);
		setPoint3Y(p3Y);
	}
	
	@Override
	public Raster raster() {
		int minx = Math.min(Math.min(point1X, point2X), point3X);
		int miny = Math.min(Math.min(point1Y, point2Y), point3Y);
		int maxx = Math.max(Math.max(point1X, point2X), point3X);
		int maxy = Math.max(Math.max(point1Y, point2Y), point3Y);
		int rasterW = maxx - minx + 1; //+1是为了将两个界都算上
		int rasterH = maxy - miny + 1;
		//创建栅格
		Raster r = new Raster(minx, miny, rasterW, rasterH);
		for(int x = minx; x < minx + rasterW; x++) {
			for(int y = miny; y < miny + rasterH; y++) {
				if(isInsideTriangle(x, y)) {
					r.setValue(x, y, 1);
				}
			}
		}
		return r;
	}
	
	//用计算当前位置在各个顶点权重的方法，来判断是否在三角形内
	public boolean isInsideTriangle(int x, int y) {
	    double alpha = (double)((point2Y - point3Y) * (x - point3X) + 
	    						(point3X - point2X) * (y - point3Y)) / 
	    				(double)((point2Y - point3Y) * (point1X - point3X) + 
	    						(point3X - point2X) * (point1Y - point3Y));

	    double beta = (double)((point3Y - point1Y) * (x - point3X) + 
	    						(point1X - point3X) * (y - point3Y)) /
	    				(double)((point2Y - point3Y) * (point1X - point3X) + 
	    						(point3X - point2X) * (point1Y - point3Y));

	    double gamma = 1 - alpha - beta;

	    // 判断点是否在三角形内
	    return alpha >= 0 && beta >= 0 && gamma >= 0 && 
	    		alpha <= 1 && beta <= 1 && gamma <= 1;
	}
	
	public int getPoint1X() {
		return point1X;
	}

	public void setPoint1X(int point1x) {
		point1X = point1x;
	}

	public int getPoint1Y() {
		return point1Y;
	}

	public void setPoint1Y(int point1y) {
		point1Y = point1y;
	}

	public int getPoint2X() {
		return point2X;
	}

	public void setPoint2X(int point2x) {
		point2X = point2x;
	}

	public int getPoint2Y() {
		return point2Y;
	}

	public void setPoint2Y(int point2y) {
		point2Y = point2y;
	}

	public int getPoint3X() {
		return point3X;
	}

	public void setPoint3X(int point3x) {
		point3X = point3x;
	}

	public int getPoint3Y() {
		return point3Y;
	}

	public void setPoint3Y(int point3y) {
		point3Y = point3y;
	}
}

