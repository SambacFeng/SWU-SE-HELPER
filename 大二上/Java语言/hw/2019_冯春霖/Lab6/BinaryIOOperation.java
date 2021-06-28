//package week14;
//
//import java.io.FileInputStream;
//import java.io.FileOutputStream;
//import java.io.IOException;
//import java.io.InputStream;
//import java.io.OutputStream;
//
//public class BinaryIOOperation {
//
//	public static void main(String[] args) {
//		InputStream is = null;
//		OutputStream os = null;
//		try
//		{
//			is = new FileInputStream("C:\\Users\\TheWait\\Documents\\作业\\Java\\Lab6\\data.txt");
//			os = new FileOutputStream("C:\\Users\\TheWait\\Documents\\作业\\Java\\Lab6\\data_copy.txt");
//			int c;
//			while((c = is.read()) != -1)
//			{
//				System.out.printf("%-2s", (char)c);
//				os.write(c);
//			}
//		}
//		catch(IOException e)
//		{
//			e.printStackTrace();
//		}
//		finally
//		{
//			try
//			{
//				if(is != null) is.close();
//				if(os != null) os.close();
//			}
//			catch (IOException e) 
//			{
//				e.printStackTrace();
//			}
//		}
//
//	}
//
//}
