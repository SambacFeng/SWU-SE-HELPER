package exp.exp3;

public class Player extends Entity {

    enum DIRECTION {
        LEFT, RIGHT, STOP
    }

    public int SPEED = 10;
    private int speed = 0;
    private DIRECTION dir = DIRECTION.STOP;

    // 依赖于动态图片类，进行动画操作
    private DynamicImage leftLookList;
    private DynamicImage rightLookList;

    // 停止前的方向
    private DIRECTION proDir = DIRECTION.STOP;

    public Player(DynamicImage leftLookList, DynamicImage rightLookList) {
        super();
        this.leftLookList = leftLookList;
        this.rightLookList = rightLookList;
        setCurrentLook(leftLookList.getImage());    // 初始化为左边
        setWidth(getCurrentLook().getWidth());
        setHeight(getCurrentLook().getHeight());
    }

    public void move() {
        DynamicImage lookList = null;
        if (getDir() == DIRECTION.LEFT) {
            lookList = getLeftLookList();
            lookList.nextFrame();
            SPEED++;    // 模拟加速过程
        } else if (getDir() == DIRECTION.RIGHT) {
            lookList = getRightLookList();
            lookList.nextFrame();
            SPEED++;    // 模拟加速过程
        } else {
            if (proDir == DIRECTION.LEFT) lookList = getLeftLookList();
            else lookList = getRightLookList();
        }
        setCurrentLook(lookList.getImage());
        System.out.println(getSpeed()); // 打印当前速度
        setPosition(getPosition().add(getSpeed(), 0));
    }

    public void right() {
        setSpeed(SPEED);
        setDir(DIRECTION.RIGHT);
    }

    public void left() {
        setSpeed(-SPEED);
        setDir(DIRECTION.LEFT);
    }

    public void stop() {
        setSpeed(0);
        proDir = dir;   // 暂存停止前的朝向
        setDir(DIRECTION.STOP);
        SPEED = 10; // 初始速度
    }


    public int getSpeed() {
        return speed;
    }


    public void setSpeed(int speed) {
        this.speed = speed;
    }


    public DynamicImage getLeftLookList() {
        return leftLookList;
    }


    public void setLeftLookList(DynamicImage leftLookList) {
        this.leftLookList = leftLookList;
    }


    public DynamicImage getRightLookList() {
        return rightLookList;
    }


    public void setRightLookList(DynamicImage rightLookList) {
        this.rightLookList = rightLookList;
    }


    public DIRECTION getDir() {
        return dir;
    }


    public void setDir(DIRECTION dir) {
        this.dir = dir;
    }
}
