package week9;

public class RegularPolygon {
	private int n = 3;
	private double side = 1;
	private double x = 0;
	private double y = 0;
	
	public RegularPolygon() {};
	
	public RegularPolygon(int _n, double _side)
	{
		setN(_n);
		setSide(_side);
	};
	
	public RegularPolygon(int _n, double _side, double _x, double _y) 
	{
		setN(_n);
		setSide(_side);
		setX(_x);
		setY(_y);
	};
	
	public void setN(int _n)
	{
		this.n = _n;
	}
	
	public int getN()
	{
		return this.n;
	}
	
	public void setSide(double _side)
	{
		this.side = _side;
	}
	
	public double getSide()
	{
		return this.side;
	}
	
	public void setX(double _x)
	{
		this.x = _x;
	}
	
	public double getX()
	{
		return this.x;
	}
	
	public void setY(double _y)
	{
		this.y = _y;
	}
	
	public double getY()
	{
		return this.y;
	}
	
	public double getPerimeter()
	{
		return (n * side);
	}
	
	public double getArea()
	{
		return (n * side * side / (4 * Math.tan(Math.PI / n)));
	}
	
	public static class test
	{
		public static void main(String[] args) 
		{
			RegularPolygon rp1 = new RegularPolygon();
			RegularPolygon rp2 = new RegularPolygon(6, 2.0);
			RegularPolygon rp3 = new RegularPolygon(4, 3.0, 1.0, 1.0);
			System.out.printf("The perimeter and the area of the "
					+ "first polygon are %4.2f and %4.2f\n", rp1.getPerimeter(),
			rp1.getArea());
			System.out.printf("The perimeter and the area of the "
					+ "second polygon are %4.2f and %4.2f\n", rp2.getPerimeter(),
			rp2.getArea());
			System.out.printf("The perimeter and the area of the "
					+ "third polygon are %4.2f and %4.2f\n", rp3.getPerimeter(),
			rp3.getArea());
		}
	}
}
