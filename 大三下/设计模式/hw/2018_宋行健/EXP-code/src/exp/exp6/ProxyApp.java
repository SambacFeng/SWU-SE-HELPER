package exp.exp6;

import java.lang.reflect.Proxy;

import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.text.Font;
import javafx.stage.Stage;

public class ProxyApp extends Application {
    int func = 0;   // 方法编号，0-加法，1-减法，2-乘法，3-除法

    @Override
    public void start(Stage primaryStage) throws Exception {
        System.getProperties().put("sun.misc.ProxyGenerator.saveGeneratedFiles", "true");
        // 动态生产代理对象
        ICalculator calculator = new Calculator();
        MyInvocationHandler mih = new MyInvocationHandler(calculator);
        ICalculator proxyInstance = (ICalculator) Proxy.newProxyInstance(calculator.getClass().getClassLoader(), new Class[]{ICalculator.class}, mih);


        Font font = new Font(18);
        VBox layout = new VBox();
        HBox loginLayout = new HBox();
        loginLayout.setPadding(new Insets(5, 5, 5, 5));
        TextField user = new TextField();
        user.setFont(font);
        TextField password = new TextField();
        password.setFont(font);
        Button login = new Button("登陆");
        login.setFont(font);
        Button logout = new Button("注销");
        logout.setFont(font);
        logout.setDisable(true);
        loginLayout.getChildren().addAll(user, password, login, logout);

        HBox addLayout = new HBox();
        addLayout.setPadding(new Insets(5, 5, 5, 5));
        TextField d1 = new TextField();
        d1.setFont(font);
        d1.setPrefWidth(100);
        Label l1 = new Label(" + ");
        l1.setFont(font);
        TextField d2 = new TextField();
        d2.setFont(font);
        d2.setPrefWidth(100);

        Button addBtn = new Button("=");
        addBtn.setFont(font);

        // 新增一个修改方法的按钮，点击按钮修改加减法
        Button changeBtn = new Button("修改方法");
        addBtn.setFont(font);

        TextField d3 = new TextField();
        d3.setFont(font);
        d3.setPrefWidth(100);
        addLayout.getChildren().addAll(d1, l1, d2, addBtn, d3, changeBtn);

        layout.getChildren().addAll(loginLayout, addLayout);

        // 加法、减法
        addBtn.setOnAction(e -> {
            d3.setText("");
            double v1 = Double.parseDouble(d1.getText());
            double v2 = Double.parseDouble(d2.getText());
            Object res = null;

            if (func == 0) {
                res = proxyInstance.add(v1, v2);    // 使用代理对象进行加法运算
            } else if (func == 1) {
                res = proxyInstance.sub(v1, v2);    // 使用代理对象进行减法运算
            } else if (func == 2) {
                res = proxyInstance.multi(v1, v2);    // 使用代理对象进行减法运算
            } else {
                if (v2 == 0) {
                    res = "（错误）";
                    Alert alert = new Alert(Alert.AlertType.ERROR);
                    alert.setTitle("计算失败");
                    alert.setHeaderText("除数不能为0！！");
                    alert.showAndWait();
                } else {
                    res = proxyInstance.div(v1, v2);    // 使用代理对象进行减法运算
                }
            }

            if (null != res)
                d3.setText(String.valueOf(res));
            else {    // 没有权限警告框
                Alert alert = new Alert(Alert.AlertType.ERROR);
                alert.setTitle("操作失败");
                alert.setHeaderText("请先登录！！！");
                alert.showAndWait();
            }
        });

        // 修改方法，点击切换加减法
        changeBtn.setOnAction(e -> {
            d3.setText("");
            double v1 = Double.parseDouble(d1.getText());
            double v2 = Double.parseDouble(d2.getText());
            Object res = null;

            // 计算
            if (func == 0) {
                l1.setText(" - ");
                func = 1;
                res = proxyInstance.sub(v1, v2);    // 使用代理对象进行减法运算
            } else if (func == 1) {
                l1.setText(" X ");
                func = 2;
                res = proxyInstance.multi(v1, v2);    // 使用代理对象进行乘法运算
            } else if (func == 2) {
                l1.setText(" / ");
                func = 3;
                if (v2 == 0) {
                    res = "（错误）";
                    Alert alert = new Alert(Alert.AlertType.ERROR);
                    alert.setTitle("计算失败");
                    alert.setHeaderText("除数不能为0！！");
                    alert.showAndWait();
                } else {
                    res = proxyInstance.div(v1, v2);    // 使用代理对象进行除法运算

                }
            } else {
                l1.setText(" + ");
                func = 0;
                res = proxyInstance.add(v1, v2);    // 使用代理对象进行加法运算
            }

            if (null != res)
                d3.setText(String.valueOf(res));
            else {    // 没有权限警告框
                Alert alert = new Alert(Alert.AlertType.ERROR);
                alert.setTitle("操作失败");
                alert.setHeaderText("请先登录！！！");
                alert.showAndWait();
            }
        });

        // 登录
        login.setOnAction(e -> {
            String u = user.getText();
            String pd = password.getText();
            if (Manager.getInstance().login(u, pd)) {
                user.setEditable(false);
                password.setEditable(false);
                login.setDisable(true);
                logout.setDisable(false);
                primaryStage.setTitle("代理模式：已登陆");
            }
        });

        // 注销
        logout.setOnAction(e -> {
            if (Manager.getInstance().isLogin()) {
                Manager.getInstance().logout();
                if (!Manager.getInstance().isLogin()) {
                    user.setEditable(true);
                    password.setEditable(true);
                    login.setDisable(false);
                    logout.setDisable(true);
                    primaryStage.setTitle("代理模式：未登陆");
                }
            }
        });

        Scene scene = new Scene(layout);
        primaryStage.setScene(scene);
        primaryStage.setTitle("代理模式：未登陆");
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
