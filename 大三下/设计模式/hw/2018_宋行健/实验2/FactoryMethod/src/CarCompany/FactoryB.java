package CarCompany;

public class FactoryB implements IFactory {
    @Override
    public Car createCar() {
        return new CarB("FrameB", "WheelB", "EngineB");
    }
}
