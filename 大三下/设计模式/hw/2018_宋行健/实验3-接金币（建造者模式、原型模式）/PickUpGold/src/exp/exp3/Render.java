package exp.exp3;

import javafx.geometry.Point2D;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.image.Image;

// 渲染类
public class Render {
	private static Render instance;
	private Canvas canvas;
	
	private Render() {
		canvas = null;
	}

	// 单例模式——懒汉模式
	public static Render getRender() {
		if(instance == null) {
			synchronized(Render.class) {
				if(instance == null) {
					instance = new Render();
				}
			}
		}
		return instance;
	}

	public void rendering () {
		if(canvas == null) {
			throw new RuntimeException("没有配置画布!");
		}
		GraphicsContext gc = canvas.getGraphicsContext2D();
		GameManager gm = GameManager.getManager();
		gc.clearRect(0, 0, canvas.getWidth(), canvas.getHeight());
		// 绘制地图
		gc.drawImage(gm.getMap().getCurrentLook(), gm.getMap().getPosition().getX(), gm.getMap().getPosition().getY());
		// 绘制角色
		gc.drawImage(gm.getPlayer().getCurrentLook(), gm.getPlayer().getPosition().getX(), gm.getPlayer().getPosition().getY());
		// 绘制金币
		for(Coin c:gm.getCoinList()) {
			Point2D pos = c.getPosition();
			Image img = c.getCurrentLook();
			gc.drawImage(img, pos.getX(), pos.getY());
		}
		// 绘制数字
		for(Number n:gm.getNumber()) {
			Point2D pos = n.getPosition();
			Image img = n.getCurrentLook();
			gc.drawImage(img, pos.getX(), pos.getY());
		}
	}
	
	public Canvas getCanvas() {
		return canvas;
	}

	public void setCanvas(Canvas canvas) {
		this.canvas = canvas;
	}
}
