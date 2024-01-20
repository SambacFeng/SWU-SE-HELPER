package exp2;

public class SmallCar {
	private boolean braked;
	private int speed;
	private int energy;
	private int location;
	
	private Road road; //一个car拥有一个可操作的道路
	
	public final static int Max_ENERGY = 100;
	public final static int RADIST_TO_ENERGYTE = 2;
	public final static int ENERGY_TO_SPEED = 3;//将能量转化为速度的过程简化为一个常量
	public final static int SPEED_LOSS = 2;
	
	public void run() {
		if(isRunning()) {
			setLocation(getLocation() + speed);
			
			if(energy != 0) {
				speed += ENERGY_TO_SPEED;
				energy--; //相当于1能量增加3速度
			}
			speed -= SPEED_LOSS; //
			if(speed < 0) { //防止speed下降到0以下
				speed = 0;
			}
			road.update(this);//将此时的car信息传递给road，更新道路信息
		}
	}
	private void setLocation(int i) {
		location = i;	
	}
	int getLocation() {
		return location;
	}
	public boolean isRunning() {
		return !braked && (speed != 0 || energy != 0);
	}
	public void accumulate(int dist) {
		energy += RADIST_TO_ENERGYTE * dist;
		if(energy > Max_ENERGY) {
			energy = Max_ENERGY;
		}
	}
	public void braked() { //用于统一设置braked制动时的状态
		this.braked = true;
		this.speed = 0;
	}
	public void released() {
		this.braked = false;
	}
	public void setRoad(Road road2) {
		road = road2;
		
	}
}


