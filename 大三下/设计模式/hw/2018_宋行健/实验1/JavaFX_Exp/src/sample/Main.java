package sample;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.image.Image;
import javafx.scene.layout.AnchorPane;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

public class Main extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception{
        Parent root = FXMLLoader.load(getClass().getResource("sample.fxml"));
        primaryStage.setTitle("Hello World");

        AnchorPane p = new AnchorPane();
        // 创建一个画布用于绘画
        Canvas c = new Canvas();
        p.getChildren().add(c);
        c.heightProperty().bind(p.heightProperty());
        c.widthProperty().bind(p.widthProperty());
        // 获取用于调用绘画功能的图形上下文对象
        GraphicsContext gc = c.getGraphicsContext2D();
        // 用白色清除上一帧的画布
//        gc.setFill(Color.WHITE);
        gc.fillRect(0, 0, c.getWidth(), c.getHeight());
//        gc.setFill(Color.BLACK);
        Image image = new Image("file:E:\\设计模式\\0_实验报告\\实验1\\JavaFX_Exp\\saber\\01.png");
        gc.drawImage(image,100,100);


        primaryStage.setScene(new Scene(root, 300, 275));
        primaryStage.show();
    }


    public static void main(String[] args) {
        launch(args);
    }
}
