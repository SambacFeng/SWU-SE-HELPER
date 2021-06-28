package week14;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class ScannerAndPrintWriter {

	public static void main(String[] args) {
		Scanner sc = null;
		PrintWriter pw = null;
		try 
		{
			sc = new Scanner(new FileInputStream("C:\\Users\\TheWait\\Documents\\作业\\Java\\Lab6\\data.txt"));
			pw = new PrintWriter("C:\\Users\\TheWait\\Documents\\作业\\Java\\Lab6\\data_copy.txt");
			while(sc.hasNextLine()) 
			{
				String line = sc.nextLine();
				System.out.println(line);
				pw.println(line);
			}
		} 
		catch (IOException e) 
		{
			e.printStackTrace();
		} 
		finally 
		{
			sc.close();
			pw.close();
		}


	}

}
