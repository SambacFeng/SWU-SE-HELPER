package exp.exp6;

import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.HashMap;
import java.util.Map;

public class Manager {
    private static final Manager instance = new Manager();
    private final Map<String, String> user2password;
    private boolean login = false;
    private PrintWriter pw;

    private Manager() {
        user2password = new HashMap<String, String>();
        user2password.put("admin", "0192023A7BBD73250516F069DF18B500"); //admin123
        try {
            pw = new PrintWriter("log.txt");
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    // 写日志
    public void log(String txt) {
        pw.println(txt);
        pw.flush(); // 写完要处理一下
    }

    public static Manager getInstance() {
        return instance;
    }

    // 登录检验
    public boolean login(String user, String pd) {
        if (user2password.containsKey(user)) {
            if (user2password.get(user).equals(md5(pd))) {
                login = true;
            }
        }
        return login;
    }

    public void logout() {
        login = false;
    }

    public boolean isLogin() {
        return login;
    }

    public String md5(String password) {
        StringBuilder sb = new StringBuilder(32);
        MessageDigest md = null;
        try {
            md = MessageDigest.getInstance("MD5");
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
        assert md != null;
        byte[] array = md.digest(password.getBytes());
        for (byte b : array) {
            sb.append(Integer.toHexString((b & 0xFF) | 0x100).toUpperCase().substring(1, 3));
        }
        return sb.toString();
    }
}
