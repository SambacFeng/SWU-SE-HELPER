package exp6.gui;

import javafx.animation.AnimationTimer;

public abstract class GameLoop extends AnimationTimer{
	private long startTime; // 循环开始时间
	private long nextTick; // 下一次游戏逻辑刷新时间
	private final int TICKS_PER_SECOND = 2;  // 默认每秒逻辑刷新次数
	private final int SKIP_TICKS = 300 / TICKS_PER_SECOND; // 逻辑刷新间隔
	private final int MAX_FRAMESKIP = 10; // 每帧最大刷新次数
	
	public GameLoop() {
		super();
		startTime = System.currentTimeMillis();
		nextTick = 0L;
	}
	
	/*
	 * 游戏循环一次，或一帧
	 */
	@Override
	public void handle(long now) {
		preprocess();
		int loops = 0;
		while((System.currentTimeMillis() - startTime) > nextTick && loops < MAX_FRAMESKIP) {
			refresh();
			nextTick += SKIP_TICKS;
			loops++;
		}
		display();
	}
	public abstract void preprocess(); // 交互相关的预处理操作
	public abstract void refresh(); // 刷新业务状态
	public abstract void display(); // 界面刷新
}
