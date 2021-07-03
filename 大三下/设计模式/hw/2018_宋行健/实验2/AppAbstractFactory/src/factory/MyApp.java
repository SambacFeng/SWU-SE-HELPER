package factory;

import game.GameLoopTimer;
import javafx.application.Application;
import javafx.geometry.Point2D;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.image.Image;
import javafx.stage.Stage;

public class MyApp extends Application {
    @Override
    public void start(Stage primaryStage) throws Exception {
        // 绘制JavaFX基本框架
        Group group = new Group();
        Scene scene = new Scene(group, 1200, 512);
        Canvas gameCanvas = new Canvas();
        GraphicsContext gc = gameCanvas.getGraphicsContext2D();
        gameCanvas.widthProperty().bind(scene.widthProperty());
        gameCanvas.heightProperty().bind(scene.heightProperty());
        group.getChildren().add(gameCanvas);
        primaryStage.setScene(scene);

        // 录入地图
        Image mapImage = new Image("file:" + System.getProperty("user.dir") + "\\image\\maps\\map03.jpg");

        // 创建工厂
        PlayerFactory playerFactory = new PlayerFactory();
        EnemyFactory enemyFactory = new EnemyFactory();

        // 调用工厂中的方法创建实例
        Building playerBuilding = playerFactory.createBuilding(new Point2D(0, 0));
        Building enemyBuilding = enemyFactory.createBuilding(new Point2D(944, 256));
        Rider playerRider = playerFactory.createRider(new Point2D(200, 200));
        Rider enemyRider1 = enemyFactory.createRider(new Point2D(600, 300));
        Rider enemyRider2 = enemyFactory.createRider(new Point2D(630, 270));
        Rider enemyRider3 = enemyFactory.createRider(new Point2D(630, 330));

        // 时间计时器循环
        GameLoopTimer timer = new GameLoopTimer() {
            @Override
            public void inputProcess() {
            }

            @Override
            public void logicUpdate() {
                playerRider.move();
                enemyRider1.move();
                enemyRider2.move();
                enemyRider3.move();
            }

            @Override
            public void displayUpdate() {
                gc.clearRect(0, 0, 1200, 512);
                gc.drawImage(mapImage, 0, 0);
                gc.drawImage(playerBuilding.getImage(), playerBuilding.getPosition().getX(), playerBuilding.getPosition().getY());
                gc.drawImage(enemyBuilding.getImage(), enemyBuilding.getPosition().getX(), enemyBuilding.getPosition().getY());
                gc.drawImage(playerRider.getCurrentImage(), playerRider.getPosition().getX(), playerRider.getPosition().getY());
                gc.drawImage(enemyRider1.getCurrentImage(), enemyRider1.getPosition().getX(), enemyRider1.getPosition().getY());
                gc.drawImage(enemyRider2.getCurrentImage(), enemyRider2.getPosition().getX(), enemyRider2.getPosition().getY());
                gc.drawImage(enemyRider3.getCurrentImage(), enemyRider3.getPosition().getX(), enemyRider3.getPosition().getY());
            }

        };

        timer.start();
        primaryStage.setResizable(false);
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }

}
