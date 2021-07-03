package CarCompany;

public class CarA extends Car {
    private final String Frame;
    private final String Wheel;
    private final String Engine;

    public CarA(String frameA, String wheelA, String engineA) {
        this.Frame = frameA;
        this.Wheel = wheelA;
        this.Engine = engineA;
    }


    public String getEngine() {
        return Engine;
    }

    public String getFrame() {
        return Frame;
    }

    public String getWheel() {
        return Wheel;
    }

    public void getInfo() {
        String Info = "-- CarA: " + Frame + " " + Wheel + " " + Engine;
        System.out.println(Info);
    }
}
