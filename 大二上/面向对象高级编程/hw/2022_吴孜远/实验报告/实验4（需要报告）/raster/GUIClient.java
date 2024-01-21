package raster;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.Button;
import javafx.stage.Stage;

public class GUIClient extends Application{

	@Override
	public void start(Stage primaryStage) throws Exception {
		
		LayerView view = new LayerView(600, 400, 2);
		Pane backPane = new Pane(view);
		
		VBox box = new VBox();
		box.getChildren().addAll(backPane);
		
		
		Scene scene = new Scene(box);
		
		//创建图形
		Circle c = new Circle(100, 100, 50);
		Rectangle r = new Rectangle(120, 120, 80, 40);
		Triangle t = new Triangle(100, 100, 60, 140, 180, 180);
		Ellipse e = new Ellipse(100, 100, 60, 40);
		//将图形栅格化
		Raster r1 = c.raster();
		Raster r2 = r.raster();
		Raster r3 = new Raster(100, 100, 120, 40);
		Raster r4 = t.raster();
		Raster r5 = e.raster();
		
		//view.render(r1);
		//view.render(r2);
		//view.render(r4);
		view.render(r5);
		//view.render(r1.intersect(r2));
		//view.render(r4.intersect(r5));
		//view.render(r1.merge(r2));
		//view.render(r4.merge(r5));
		//view.render(r1.clip(r3));
		
		
		primaryStage.setResizable(false);
		primaryStage.setScene(scene);
		primaryStage.setTitle("栅格化");
		primaryStage.show();
	}

	public static int random(int max) {
		return (int) (Math.random() * (max + 1));
	}
	
	public static void main(String[] args) {
		launch();
	}
}
