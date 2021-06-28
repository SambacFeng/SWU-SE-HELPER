package week14;

public abstract class GeometricObject implements Comparable<GeometricObject>
{
	public abstract double getArea();
	public int compareTo(GeometricObject g)
	{
		if (this.getArea() > g.getArea())
			return 1;
		else if (this.getArea() == g.getArea())
			return 0;
		else
			return -1;
	}
}
