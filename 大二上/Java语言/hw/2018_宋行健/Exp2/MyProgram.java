import java.util.Scanner;
public class MyProgram{
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        System.out.print("Please input r: ");
        double r = input.nextDouble();

        while (true){
            System.out.print("Whether to continue:  ");
            String a = input.next();
            if(a.equals("N"))break;

            System.out.print("Enter a point with two coordinates: ");
            double x = input.nextDouble();
            double y = input.nextDouble();

            double d = Math.sqrt(x*x+y*y);
            if(d < r)
                System.out.println(String.format("Point (%.2f, %.2f) is in the circle.",x,y));
            else if(d == r)
                System.out.println(String.format("Point (%.2f, %.2f) is on the circle.",x,y));
            else
                System.out.println(String.format("Point (%.2f, %.2f) is not in the circle.",x,y));

        }
    }
}