package exp.exp6;

// 被代理的对象
public class Calculator implements ICalculator {

    @Override
    public Double add(double x, double y) {
        return x + y;
    }
    @Override
    public Double sub(double x, double y) { return x - y; }
    @Override
    public Double multi(double x, double y) { return x * y; }
    @Override
    public Double div(double x, double y) { return x / y; }
}
