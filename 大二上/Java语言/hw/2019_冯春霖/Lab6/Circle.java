package week14;

public class Circle extends GeometricObject
{
	private int id;
	private double radius;
	public Circle(int id) { this.id = id;}
	public Circle(int id, double r) 
	{
		this.id = id;
		this.radius = r;
	}
	
	public double getRadius()
	{
		return radius;
	}
	
	public void setRadius(double _r)
	{
		radius = _r;
	}

	//@Override
	public double getArea() 
	{
		return (radius * radius * Math.PI);
	}
	
	@Override
	public String toString() 
	{
		return id + ",circle," + this.getArea();
	}
}