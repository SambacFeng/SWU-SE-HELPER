package exp.exp3;

import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.image.Image;
import javafx.stage.Stage;

import java.nio.file.Paths;

public class MainApp extends Application {
	
	@Override
	public void start(Stage primaryStage) {

		//初始化游戏控制与管理模块
		GameManager manager = GameManager.getManager();
		GameController controller = GameController.getController();
		Render render = Render.getRender();

		//初始化基础GUI界面
		Group group = new Group();
		Canvas gameCanvas = new Canvas();		
        group.getChildren().add(gameCanvas);
        Scene scene = new Scene(group, manager.getMap().getWidth(), manager.getMap().getHeight());
        gameCanvas.widthProperty().bind(scene.widthProperty());
        gameCanvas.heightProperty().bind(scene.heightProperty());
		primaryStage.setScene(scene);
		primaryStage.setTitle("设计模式");	// 标题
		primaryStage.getIcons().add(new Image(Paths.get("bin\\images\\0sxj.jpg").toUri().toString()));	// 图标

		// 为渲染器配置画布
		render.setCanvas(gameCanvas);
		
		// 输入事件处理，按键行走，松开停下
		scene.setOnKeyPressed(e -> {
			e.consume();
			controller.add(e.getCode().toString());
		});
		scene.setOnKeyReleased(e -> {
			e.consume();
			controller.add("STOP");
		});

		// 计时器
		GameLoopTimer timer = new GameLoopTimer() {
			@Override
			public void inputProcess() {
				controller.process();
			}
			@Override
			public void logicUpdate() {
				manager.update();
			}
			@Override
			public void displayUpdate() {
				render.rendering();
			}
        };
        
        timer.start();
        primaryStage.show();
        primaryStage.setResizable(false);
		
	}

	public static void main(String[] args) {
		launch(args);
	}

}
