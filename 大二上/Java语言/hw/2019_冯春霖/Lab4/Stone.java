package week9;

public class Stone {
		public final static int WHITE = 0;
		public final static int BLACK = 1;
		private int color;
		
		public Stone(int color) 
		{
			this.setColor(color);
		}
		
		public int getColor() 
		{
			return color;
		}
		
		public void setColor(int color) 
		{
			this.color = color;
		}
		
		public static String colorToString(int color) 
		{
			return color == WHITE ? "white": "black";
		}
		
		public char getShape() 
		{
			return color == WHITE ? '\u25CB': '\u25CF';
		}

}
