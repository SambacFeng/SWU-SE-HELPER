package exp2;

public class Player {
	private SmallCar car;
	public Player(SmallCar car) {
		this.car = car;
	}
	public void push(int distance) {
		car.braked();
		car.accumulate(distance);
	}
	public void release() {
		car.released();
	}
}
