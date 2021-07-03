package exp.exp7.example;

public class Context {
    State state;

    public static void main(String[] args) {
        Context c = new Context();
        c.state = new ConcreteStateA();
        c.request();
    }

    public void request() {
        // 将全局的条件分支的设计，局部化。
        state.handle(this);
    }
}
