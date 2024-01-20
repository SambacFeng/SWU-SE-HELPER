package exp2;

public class Test {
	public static void main(String[] args) {
		SmallCar car = new SmallCar();
		Player player = new Player(car);
		Road road = new Road(100);
		car.setRoad(road);
		// 游戏过程
		player.push(2);
		player.release();
		while (car.isRunning()) {
			car.run();
			System.out.print(road.show('r', 'C')); // 屏幕刷新
			try {
				Thread.sleep(100);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}

}
