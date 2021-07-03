package Exp1;

import javafx.animation.AnimationTimer;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.layout.AnchorPane;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.stage.Stage;


public class TimerTest extends Application {
    @Override
    public void start(Stage primaryStage) throws Exception {
        AnchorPane p = new AnchorPane();
        // 创建一个画布用于绘画
        Canvas c = new Canvas();
        p.getChildren().add(c);
        c.heightProperty().bind(p.heightProperty());
        c.widthProperty().bind(p.widthProperty());
        // 获取用于调用绘画功能的图形上下文对象
        GraphicsContext gc = c.getGraphicsContext2D();
        // 创建计时器匿名类对象，在handle方法中定义每帧的行为
        AnimationTimer at = new AnimationTimer() {
            int x = 100;
            int y = 100;
            int add = 1;

            @Override
            public void handle(long now) {
                // 用白色清除上一帧的画布
                gc.setFill(Color.WHITE);
                gc.fillRect(0, 0, c.getWidth(), c.getHeight());
                gc.setFill(Color.BLACK);
                // 设置字体，绘制一个文本
                gc.setFont(new Font(22));
                gc.fillText("Hello", x, y);
                // 更新位置信息
                x += add;
                if (x == 200) {
                    add = -1;
                } else if (x == 100) {
                    add = 1;
                }
            }
        };
        at.start();
        primaryStage.setScene(new Scene(p));
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
