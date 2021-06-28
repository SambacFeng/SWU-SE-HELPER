package week14;

public class Rectangle extends GeometricObject
{
	private int id;
	private double width;
	private double height;
	
	public Rectangle(int id) { this.id = id;}
	
	public Rectangle(int id, double width, double height) 
	{
		this.id = id;
		this.width = width;
		this.height = height;
	}
	
	public int getId() 
	{
		return id;
	}
	
	public void setId(int id) 
	{
		this.id = id;
	}
	
	public double getWidth() 
	{
		return width;
	}
	
	public void setWidth(double width) 
	{
		this.width = width;
	}
	
	public double getHeight() 
	{
		return height;
	}
	
	public void setHeight(double height) 
	{
		this.height = height;
	}

	@Override
	public double getArea() 
	{
		return width * height;
	}
	
	public String toString() 
	{
		return id + ",rectangle," + this.getArea();
	}
}