package exp.exp6;

// 计算接口
public interface ICalculator {
    public Double add(double x, double y);    // 返回的是 Object 和 Double 兼容性更好
    public Double sub(double x, double y);
    public Double multi(double x, double y);
    public Double div(double x, double y);
}
