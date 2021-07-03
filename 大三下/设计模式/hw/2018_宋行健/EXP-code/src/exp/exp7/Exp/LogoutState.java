package exp.exp7.Exp;

import java.net.InetAddress;
import java.net.UnknownHostException;

public class LogoutState implements ILoginState {
    @Override
    public void handle(MessageBoard mb) {
        login(mb);
    }

    private void login(MessageBoard mb) {
        System.out.print("LOGIN:(Y/N): ");
        String str = mb.input();
        if (str.equals("Y") || str.equals("y")) {
            // 提示游客登陆成功
            try {
                String ip = InetAddress.getLocalHost().getHostAddress();
                System.out.println("Visitor: [" + ip + "] Login Successfully");
                System.out.println("******************************* Message Board *******************************\n" +
                                   "---------------     Type \"D\" to view the history message.     ---------------\n"+
                                   "-------------------------     Type \"Q\" to exit.     -------------------------\n");
            } catch (UnknownHostException e) {
                e.printStackTrace();
            }

            // 修改留言板状态
            mb.setState(MessageBoard.LOGIN);
        }
    }
}
