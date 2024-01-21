package exp6.gui;

import exp6.biz.*;

import javafx.application.Application;
import javafx.stage.Stage;

import javafx.scene.layout.VBox;
import javafx.scene.Scene;
import javafx.scene.image.Image;

public class MainApp extends Application{
	
	public static void main(String[] args) {
		launch(args);
	}
	
	@Override
	public void start(Stage primaryStage) throws Exception {
		final int mapWidth = 30, mapHeight = 20, viewWidth = 20, viewHeight = 12;
		
		
		// 业务类
		GameMap map = new GameMap(mapWidth, mapHeight);
		for(int x = 0; x < mapWidth; x++) {
			for(int y = 0; y < mapHeight; y++) {
				map.put(x, y, (int)(Math.random() * 3)); // 0/1/2
			}
		}
		ViewArea view = new ViewArea(0, 0, viewWidth, viewHeight);
		view.setTarget(map);
		Controller c = new Controller(view);
		
		for(int i = 0;i<3;i++) {
			int x,y;
			while(true) {
				 x = (int) (Math.random()* view.getWidth());
				 y = (int) (Math.random()* view.getHeight());
				if(map.get(x, y) != 2 ) {
					break;
				}
			}
			c.addBall((new Ball(x,y)));
		}
		//c.addBall(new Ball(10, 10));
		//c.addBall(new Ball(12, 3));
		//c.addBall(new Ball(4, 6));
		
		// 业务相关界面类
		MapViewer viewer = new MapViewer(c, 64);
		viewer.put("map0", new Image("001.png"));
		viewer.put("map1", new Image("002.png"));
		viewer.put("map2", new Image("003.png"));//水
		viewer.put("ball0", new Image("football01.png"));
		viewer.put("ball1", new Image("football02.png"));
		
		
		// 游戏循环，动态要素
		GameLoop gl = new GameLoop() {

			@Override
			public void preprocess() {}

			@Override
			public void refresh() {
				c.executeAll();
			}

			@Override
			public void display() {
				viewer.render();
			}
			
		};
		
		gl.start();
		
		// 界面布局
		VBox box = new VBox();
		box.getChildren().addAll(viewer);
		
		Scene scene = new Scene(box);
		
		primaryStage.setScene(scene);
		primaryStage.setResizable(false);
		primaryStage.setTitle("小游戏");
		primaryStage.show();
	}

}
