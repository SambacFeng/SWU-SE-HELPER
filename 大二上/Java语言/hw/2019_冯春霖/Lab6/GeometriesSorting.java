package week14;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class GeometriesSorting {

	public static void main(String[] args) {
		sort("C:\\Users\\TheWait\\Documents\\作业\\Java\\Lab6\\data.txt", "C:\\Users\\TheWait\\Documents\\作业\\Java\\Lab6\\results.txt");
	}

	public static GeometricObject CreateGeoByString(String s)
	{
		GeometricObject g = null;
		String[] items = s.split(",");
		int id = Integer.parseInt(items[0]);
		String type = items[1];
		switch(type) 
		{
			case "circle":
			{
				double r = Double.parseDouble(items[2]);
				g = new Circle(id, r);
			} break;
			case "rectangle": 
			{
				double width = Double.parseDouble(items[2]);
				double height = Double.parseDouble(items[3]);
				g = new Rectangle(id, width, height);
			} break;
			case "triangle": 
			{
				double a = Double.parseDouble(items[2]);
				double b = Double.parseDouble(items[3]);
				double c = Double.parseDouble(items[4]);
				g = new Triangle(id, a, b, c);
			} break;
		}
		
		return g;
	}
	
	public static void sort(String dataPath, String resultsPath) 
	{
		Scanner input = null;
		PrintWriter pw = null;
		
		try {
			input = new Scanner(new FileInputStream(dataPath));
			pw = new PrintWriter(resultsPath);
			ArrayList<GeometricObject> geoList = new ArrayList<GeometricObject>();
			// Reader all lines from the data file and create geometries
			while (input.hasNextLine())
			{
				String str = input.nextLine();
				geoList.add(CreateGeoByString(str));
			}
			// Sort the list by Collections.sort()
			Collections.sort(geoList);
			// Output the sorted geometry list to target file
			for(GeometricObject g : geoList)
			{
				pw.println(g.toString());
			}
			System.out.println();
		} catch (IOException e) {
			System.out.println("Reading or Writing Error!");
		} finally {
			input.close();
			pw.close();
		}
	}



}
