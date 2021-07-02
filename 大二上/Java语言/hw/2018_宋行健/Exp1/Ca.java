import java.util.Scanner;
public class Ca{
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        System.out.println("Input an equation (ax + by = e): ");

        System.out.print("Enter a: ");
        double a = input.nextDouble();
        System.out.print("Enter b: ");
        double b = input.nextDouble();
        System.out.print("Enter e: ");
        double e = input.nextDouble();
        System.out.println("Equation A: "+ a +"x + "+ b +"y = "+ e + "\n");

        System.out.println("Input an equation (cx + dy = f): ");
        System.out.print("Enter c: ");
        double c = input.nextDouble();
        System.out.print("Enter d: ");
        double d = input.nextDouble();
        System.out.print("Enter f: ");
        double f = input.nextDouble();
        System.out.println("Equation B: "+ c +"x + "+ d +"y = "+ f);

        double x = (e * d - b * f)/(a * d - b * c);
        double y = (a * f - e * c)/(a * d - b * c);
        System.out.println(String.format("x=%.2f\ty=%.2f",x,y));
        //System.out.println("x="+x+"\ty="+y);
    }
}