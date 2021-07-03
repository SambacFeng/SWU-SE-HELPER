package exp.exp7.example;

public class ConcreteStateB implements State {
    @Override
    public void handle(Context context) {
        System.out.println("B");
    }
}
