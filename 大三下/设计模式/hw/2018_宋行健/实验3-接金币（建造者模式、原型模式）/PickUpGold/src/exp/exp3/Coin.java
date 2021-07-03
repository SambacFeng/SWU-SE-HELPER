package exp.exp3;


import javafx.geometry.Point2D;

public class Coin extends Entity implements Cloneable {
    private DynamicImage lookList;
    private int speed = 0;


    public Coin(DynamicImage lookList) {
        super();
        setLookList(lookList);
        setCurrentLook(lookList.getImage());
        setPosition(new Point2D(0, 0));
        setWidth(getCurrentLook().getWidth());
        setHeight(getCurrentLook().getHeight());
    }

    // 金币移动
    public void move() {
        lookList.nextFrame();    // 图片切换
        setCurrentLook(lookList.getImage());
        setSpeed(speed + 1);    // 模仿重力加速度
        setPosition(getPosition().add(0, getSpeed()));    // 位置切换
    }

    // 原型模式——克隆，深复制。
    @Override
    public Object clone() throws CloneNotSupportedException {
        Coin c = (Coin) super.clone();
        c.setLookList((DynamicImage) this.getLookList().clone());
        return c;
    }

    public int getSpeed() {
        return speed;
    }

    public void setSpeed(int speed) {
        this.speed = speed;
    }

    public DynamicImage getLookList() {
        return lookList;
    }

    public void setLookList(DynamicImage lookList) {
        this.lookList = lookList;
    }
}
