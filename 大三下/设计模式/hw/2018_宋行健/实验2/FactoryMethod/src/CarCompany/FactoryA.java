package CarCompany;

public class FactoryA implements IFactory {
    @Override
    public Car createCar() {
        return new CarA("FrameA", "WheelA", "EngineA");
    }
}
