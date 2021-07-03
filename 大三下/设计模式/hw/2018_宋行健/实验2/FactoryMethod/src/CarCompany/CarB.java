package CarCompany;

public class CarB extends Car {
    private final String Frame;
    private final String Wheel;
    private final String Engine;

    public CarB(String frameB, String wheelB, String engineB) {
        this.Frame = frameB;
        this.Wheel = wheelB;
        this.Engine = engineB;
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
        String Info = "-- CarB: " + Frame + " " + Wheel + " " + Engine;
        System.out.println(Info);
    }
}
