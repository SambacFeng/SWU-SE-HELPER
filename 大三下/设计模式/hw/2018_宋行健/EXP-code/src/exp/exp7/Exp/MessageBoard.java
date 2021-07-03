package exp.exp7.Exp;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class MessageBoard {
    private final List<String> messageList;
    private ILoginState state;
    public static ILoginState LOGIN = new LoginState();
    public static ILoginState LOGOUT = new LogoutState();

    public MessageBoard(ILoginState state) {
        super();
        this.state = state;
        this.messageList = new ArrayList<String>();
    }

    // 客户端对留言板发出请求，留言板根据当前状态运行
    public void request() {
        state.handle(this);
    }

    public void display() {
        // 显示所有留言
        System.out.println("\n******************************* Message Board *******************************");
        for (String message : messageList) {
            System.out.println("-->" + message);
        }
        System.out.println();
    }

    public void addMessage(String m) {
        // 添加消息
        messageList.add(m);
    }

    public String input() {
        Scanner input = new Scanner(System.in);
        return input.next();
    }

    public void setState(ILoginState logout) {
        state = logout;
    }
}
