package factory;

import game.ImageTool;
import javafx.geometry.Point2D;
import javafx.scene.image.Image;

public class PlayerFactory implements IFactory {
    Image resource = new Image("file:" + System.getProperty("user.dir") + "\\image\\res\\res01.png");

    @Override
    public PlayerRider createRider(Point2D pos) {
        Image[] images = new Image[3];
        for (int i = 0; i < 3; i++) {
            images[i] = ImageTool.clipImage(resource, 540 + i * 110, 370, 110, 80);
        }
        return new PlayerRider(images, pos);
    }

    @Override
    public PlayerBuilding createBuilding(Point2D pos) {
        Image house = ImageTool.clipImage(resource, 600, 0, 240, 256);
        return new PlayerBuilding(house, pos);
    }
}
