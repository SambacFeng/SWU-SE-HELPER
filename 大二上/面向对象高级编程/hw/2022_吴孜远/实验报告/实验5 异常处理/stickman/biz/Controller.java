package exp5.stickman.biz;

import exp5.stickman.entity.Joint;
import exp5.stickman.entity.StickMan;
import exp5.stickman.entity.StickMan.JointType;
import exp5.stickman.exception.SearchRadiusException;
import exp5.stickman.utils.MyMath;

public class Controller {
	private StickMan stickMan;
	private Joint focused;
	private Joint fixed;
	private double tolerance = 10; // 鼠标选择容错范围
	
	public Controller(StickMan man){
		this.setStickMan(man);
	}
	
	// 鼠标聚焦的节点
	public void focus(double x, double y){
		try {
			focused = stickMan.search(x, y, tolerance);
		}catch(SearchRadiusException e) {
			System.out.println(e);
		}
			
	}
	
	// (x1,y1)(x2,y2)界面拖动前后的两个点
	public void move(double x1, double y1, double x2, double y2) {
		// 已经发生拖动
		if(x1 > 0 && y1 > 0) {
			// 没有固定点就平移
			if(fixed == null) {
				if(focused != null) {
					stickMan.move(x2 - x1, y2 - y1);
				}
			}else {
				if(stickMan.existStick(focused, fixed)) {
					double a = MyMath.dist(x1, y1, x2, y2);
					double b = MyMath.dist(x1, y1, fixed.getX(), fixed.getY());
					double c = MyMath.dist(x2, y2, fixed.getX(), fixed.getY());
					double cosA = (Math.pow(b, 2) + Math.pow(c, 2) - Math.pow(a, 2)) / (2 * b * c);
					double A = Math.abs(Math.acos(cosA));
					// 是否顺时针判断
					if((x1 - fixed.getX()) * (y2 - fixed.getY()) - (x2 - fixed.getX()) * (y1 - fixed.getY()) < 0) {
						A = -A;
					}
					stickMan.rotate(fixed, focused, A);
				}
			}
		}
	}
	
	// 固定住当前聚焦的点
	public void fix() {
		if(focused != null) {
			if(focused != fixed) {
				fixed = focused;
			}else {
				fixed = null;
			}
		}
	}
	
	// 取消固定
	public void release() {
		if(focused == fixed) {
			fixed = null;
		}
	}
	
	public double[] getFocused() {
		if(focused != null) {
			return new double[] {focused.getX(), focused.getY()};
		}
		return null;
	}
	public double[] getFixed() {
		if(fixed != null) {
			return new double[] {fixed.getX(), fixed.getY()};
		}
		return null;
	}
	public double[][] getPoints(){
		return stickMan.allPointCoordinates();
	}
	public double[][] getLines(){
		return stickMan.allStickCoordinates();
	}
	
	public double[][] getHead(){
		return new double[][] {stickMan.point(JointType.HeadTop), stickMan.point(JointType.HeadDown)};
	}
	
	public StickMan getStickMan() {
		return stickMan;
	}

	public void setStickMan(StickMan stickMan) {
		this.stickMan = stickMan;
	}
	
}
