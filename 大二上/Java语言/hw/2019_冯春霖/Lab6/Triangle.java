package week14;

public class Triangle extends GeometricObject
{
	private int id;
	private double a;
	private double b;
	private double c;
	
	public Triangle(int id) { this.setId(id);}
	
	public Triangle(int id, double a, double b, double c)
	{
		this.setId(id);
		this.setA(a);
		this.setB(b);
		this.setC(c);
	}
	
	public int getId() 
	{
		return id;
	}
	
	public void setId(int id) 
	{
		this.id = id;
	}
	
	public double getA() 
	{
		return a;
	}
	
	public void setA(double a) 
	{
		this.a = a;
	}
	
	public double getB() 
	{
		return b;
	}
	
	public void setB(double b) 
	{
		this.b = b;
	}
	
	public double getC() 
	{
		return c;
	}
	
	public void setC(double c) 
	{
		this.c = c;
	}
	
	@Override
	public double getArea() 
	{
		double p = (a + b + c) / 2;
		return Math.sqrt(p * (p - a) * (p - b) * (p - c));
	}

	// Return information format: "id,triangle,area"
	public String toString() 
	{
		return id + ",triangle," + this.getArea();
	}
}