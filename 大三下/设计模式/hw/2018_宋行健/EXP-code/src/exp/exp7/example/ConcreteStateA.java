package exp.exp7.example;

public class ConcreteStateA implements State{
    @Override
    public void handle(Context context) {
        System.out.println("A");
        // 跳转到 B 状态（下一个状态）
        context.state = new ConcreteStateB();
        context.state.handle(context);
    }
}
