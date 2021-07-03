package factory;

import game.ImageTool;
import javafx.geometry.Point2D;
import javafx.geometry.Point3D;
import javafx.scene.image.Image;

public class EnemyFactory implements IFactory {
    Image resource = new Image("file:" + System.getProperty("user.dir") + "\\image\\res\\res02.png");

    @Override
    public EnemyRider createRider(Point2D pos) {
        Image[] images = new Image[3];
        for (int i = 0; i < 3; i++) {
            images[i] = ImageTool.rotate(ImageTool.clipImage(resource, 10 + i * 100, 860, 100, 70), 180, new Point3D(0, 1, 0));
        }
        return new EnemyRider(images, pos);
    }

    @Override
    public EnemyBuilding createBuilding(Point2D pos) {
        Image house = ImageTool.clipImage(resource, 0, 0, 240, 256);
        return new EnemyBuilding(house, pos);
    }
}
