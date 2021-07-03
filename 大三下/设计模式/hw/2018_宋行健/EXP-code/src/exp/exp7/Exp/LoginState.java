package exp.exp7.Exp;

import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.Date;

public class LoginState implements ILoginState {
    @Override
    public void handle(MessageBoard mb) {
        System.out.print("Please enter a message: ");
        String str = mb.input();
        if (str.equals("Q") || str.equals("q")) {
            System.out.println("\nEXIT ...\n");
            mb.setState(MessageBoard.LOGOUT);
        } else if (str.equals("D") || str.equals("d")) {
            mb.display();
        } else {
            try {
                String ip = InetAddress.getLocalHost().getHostAddress();
                mb.addMessage(str + "\t" + ip + "\t" + new Date());
            } catch (UnknownHostException e) {
                e.printStackTrace();
            }
        }
    }
}
