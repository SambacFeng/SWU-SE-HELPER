package factory;

import javafx.geometry.Point2D;

public interface IFactory {
    Rider createRider(Point2D pos);

    Building createBuilding(Point2D pos);
}
