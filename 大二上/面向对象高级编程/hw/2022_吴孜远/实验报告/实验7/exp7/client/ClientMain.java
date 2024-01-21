package exp7.client;


import java.text.SimpleDateFormat;
import java.util.Date;

import exp7.entity.ChatRecord;
import javafx.application.Application;
import javafx.application.Platform;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class ClientMain extends Application{
	String current = "";
	public static void main(String[] args) {
		launch(args);
	}

	@Override
	public void start(Stage primaryStage) throws Exception {
		
		ChatClient chatClient = new ChatClient();

		VBox layout = new VBox();
		
		HBox header = new HBox();
		VBox body = new VBox();

		//头部：服务器连接配置区域
		Label l1 = new Label("地址:");
		Label l2 = new Label("端口:");
		TextField address = new TextField("localhost");
		TextField port = new TextField("8189");
		Button btn = new Button("连接");
		Label l3 = new Label("昵称:");
		TextField name = new TextField("匿名");
		header.getChildren().addAll(l1, address, l2, port, btn, l3, name);
		
		
		// 文字区域
		SimpleDateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss E");
		TextArea messageArea = new TextArea();
		messageArea.setPrefHeight(500);
		TextField mf = new TextField();
		mf.setPrefWidth(950);
		Button sendBtn = new Button("发送");
		HBox editor = new HBox();
		editor.getChildren().addAll(mf, sendBtn);
		sendBtn.setOnAction(e -> {
			if(mf.getText().length() != 0) {
				chatClient.sendChat(new ChatRecord(name.getText(), dateFormat.format(new Date()), mf.getText()));
			}
		});
		body.getChildren().addAll(messageArea, editor);
		
		// 底部：状态信息
		TextArea stateArea = new TextArea();
		
		// 实时获取服务器数据
		Thread updateThread = new Thread(() -> {
			while(true) {
				// 持续发送获取服务器数据请求
				try {
					String data = chatClient.get();
					if(!data.equals(current)) {
						current = data;
						// 图形界面主线程处理任务
						Platform.runLater(() -> {
							messageArea.clear();
							messageArea.appendText(data);
						});
					}
					Thread.sleep(100);
				} catch (Exception e1) {
					e1.printStackTrace();
				}
			}
		});
		
		// 连接服务器
		btn.setOnAction(e -> {
			String ip = address.getText();
			int p = Integer.parseInt(port.getText());
			chatClient.connect(ip, p);
			if(chatClient.isConnected()) {
				updateThread.start();
			}
		});
		
		
		layout.getChildren().addAll(header, body, stateArea);
		Scene scene = new Scene(layout, 1000, 600);
		
		primaryStage.setScene(scene);
		primaryStage.show();
	}
	
	
	
	
}
