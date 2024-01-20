package exp2;

import java.util.Arrays;

public class Road {
	private int length;
	private int carLocation;
	
	public Road(int len) {
		carLocation = -1;
		length = len;
	}
	public String show(char r, char c) {
		StringBuilder view = new StringBuilder();
		char[] temp = new char[length];
		Arrays.fill(temp, '\b');
		view.append(temp);
		Arrays.fill(temp, 'r');
		temp[carLocation] = c;
		view.append(temp);
		return view.toString();

	}
	public void update(SmallCar car) {
		if(car.getLocation() < length) {
		carLocation = car.getLocation();
		}else {
		carLocation = length - 1;
		}
}
}
