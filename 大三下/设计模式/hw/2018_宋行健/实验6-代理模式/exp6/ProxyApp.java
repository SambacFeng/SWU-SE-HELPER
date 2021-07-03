package exp.exp6;

import java.lang.reflect.Proxy;
import java.security.MessageDigest;

import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.text.Font;
import javafx.stage.Stage;

public class ProxyApp extends Application{

	@Override
	public void start(Stage primaryStage) throws Exception {
		
		
		IAdd add = new Calculator();
		MyInvocationHandler mih = new MyInvocationHandler(add);
		IAdd addProxy = (IAdd) Proxy.newProxyInstance(add.getClass().getClassLoader(), new Class[] {IAdd.class}, mih);
		
		
		
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
		Label l1 = new Label("+");
		l1.setFont(font);
		TextField d2 = new TextField();
		d2.setFont(font);
		d2.setPrefWidth(100);
		Button addBtn = new Button("=");
		addBtn.setFont(font);
		TextField d3 = new TextField();
		d3.setFont(font);
		d3.setPrefWidth(100);
		addLayout.getChildren().addAll(d1, l1, d2, addBtn, d3);
		
		layout.getChildren().addAll(loginLayout, addLayout);
		
		
		
		addBtn.setOnAction(e -> {
			d3.setText("");
			double v1 = Double.parseDouble(d1.getText());
			double v2 = Double.parseDouble(d2.getText());
			Object res = addProxy.add(v1, v2);
			if(res != null)
				d3.setText(String.valueOf(res));
		});
		login.setOnAction(e -> {
			String u = user.getText();
			String pd = password.getText();
			if(Manager.getInstance().login(u, pd)) {
				user.setEditable(false);
				password.setEditable(false);
				login.setDisable(true);
				logout.setDisable(false);
				primaryStage.setTitle("代理模式：已登陆");
			}
		});
		logout.setOnAction(e -> {
			if(Manager.getInstance().isLogin()) {
				Manager.getInstance().logout();
				if(!Manager.getInstance().isLogin()) {
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
