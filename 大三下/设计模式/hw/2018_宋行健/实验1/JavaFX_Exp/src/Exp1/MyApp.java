package Exp1;

import javafx.animation.AnimationTimer;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.image.Image;
import javafx.scene.layout.AnchorPane;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

public class MyApp extends Application {
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
            final int velocity = 1;   // 每一帧前进的距离
            final int startPoint = 0;
            final int endPoint = 500;
            double x = startPoint;
            int num = 0;    // 动画编号

            @Override
            public void handle(long now) {
                String Path = "file:E:\\设计模式\\0_实验报告\\实验1\\JavaFX_Exp\\saber\\0" + Integer.toString(num / 10 + 1) + ".png";
                num = (num + 1) % 80;

                System.out.println(x);

                // 用白色清除上一帧的画布
                gc.setFill(Color.WHITE);
                gc.fillRect(0, 0, c.getWidth(), c.getHeight());
                gc.setFill(Color.BLACK);
                Image image = new Image(Path);
                gc.drawImage(image, x, 10);

                // 更新位置信息
                x += velocity;
                if (x == endPoint) {
                    // 图像翻转
                    x = startPoint;     // 回归起点
                    // 将gc的坐标原点平移到画布的(x,0)
                    // 这里加上一个图片宽度(image.getWidth())是为了让人物可以原地旋转
                    gc.translate(startPoint + endPoint + image.getWidth(), 0);
                    gc.scale(-1, 1); // 水平翻转
                    System.out.println("======");
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
