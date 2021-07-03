package exp.exp7.Exp;

public class Test {
    public static void main(String[] args) {
        MessageBoard mb = new MessageBoard(new LogoutState());
        while (true) {
            mb.request();
        }
    }
}
