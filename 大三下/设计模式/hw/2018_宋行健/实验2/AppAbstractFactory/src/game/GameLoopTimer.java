package game;

import javafx.animation.AnimationTimer;

public abstract class GameLoopTimer extends AnimationTimer{
	private long startTime;
	private long nextTick;
	private final int TICKS_PER_SECOND = 10;
	private final int SKIP_TICKS = 1000 / TICKS_PER_SECOND;
	private final int MAX_FRAMESKIP = 10;
	
	public GameLoopTimer() {
		super();
		startTime = System.currentTimeMillis();
		nextTick = 0L;
	}
	
	@Override
	public void handle(long now) {
		inputProcess();
		int loops = 0;
		while((System.currentTimeMillis() - startTime) > nextTick && loops < MAX_FRAMESKIP) {
			logicUpdate();
			nextTick += SKIP_TICKS;
			loops++;
		}
		displayUpdate();
	}
	public abstract void inputProcess();
	public abstract void logicUpdate();
	public abstract void displayUpdate();
}
