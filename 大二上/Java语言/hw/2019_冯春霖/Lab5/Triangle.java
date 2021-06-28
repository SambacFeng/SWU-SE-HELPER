package week12;

public class Triangle {
	double side1 = 1.0;
	double side2 = 1.0;
	double side3 = 1.0;
	
	public Triangle() {};
	
	public Triangle(double _s1, double _s2, double _s3) throws Exception
	{
		if(_s1 <= 0)
			throw new IllegalTriangleException("_s1 <= 0");
		else if(_s2 <= 0)
			throw new IllegalTriangleException("_s2 <= 0");
		else if(_s3 <= 0)
			throw new IllegalTriangleException("_s3 <= 0");
		else if(_s1 + _s2 <= _s3)
			throw new IllegalTriangleException("_s1 + _s2 <= _s3");
		else if(_s1 + _s3 <= _s2)
			throw new IllegalTriangleException("_s1 + _s3 <= _s2");
		else if(_s2 + _s3 <= _s1)
			throw new IllegalTriangleException("_s2 + _s3 <= _s1");
		side1 = _s1;
		side2 = _s2;
		side3 = _s3;
	}
	
	public double getSide1()
	{
		return side1;
	}

	public double getSide2()
	{
		return side2;
	}
	
	public double getSide3()
	{
		return side3;
	}
	
	public double getArea()
	{
		double p = (side1 + side2 + side3) / 2;
		return Math.sqrt(p * (p - side1) * (p - side2) * (p - side3));
	}
	
	public String toString()
	{
		return "Three sides of the triangle are " + side1 + ", " + side2 + ", "  + side3;
	}
	
	class IllegalTriangleException extends Exception
	{
		private static final long serialVersionUID = 1L;
		
		public IllegalTriangleException(String msg)
		{
			super(msg);
		}
		
	}
}
