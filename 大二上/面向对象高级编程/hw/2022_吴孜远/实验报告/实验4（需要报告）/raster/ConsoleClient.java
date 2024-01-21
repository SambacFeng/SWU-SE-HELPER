package raster;


// 基于控制台的客户端
public class ConsoleClient {
	public static void main(String[] args) {
		Shape c = new Circle(15, 15, 5);
		Shape r = new Rectangle(19, 19, 8, 8);
		Raster r1 = c.raster();
		Raster r2 = r.raster();
		printRaster(r1);
		//printRaster(r2);
	}
	
	// 打印一个栅格对象
	public static void printRaster(Raster r) {
		for(int y = 0; y < r.getEndY(); y++) {
			for(int x = 0; x < r.getEndX(); x++) {
				if(r.getValue(x, y) == 1) {
					System.out.printf("%2s", "*");
				}else {
					System.out.printf("%2s", " ");
				}
			}
			System.out.println();
		}
	}
}
