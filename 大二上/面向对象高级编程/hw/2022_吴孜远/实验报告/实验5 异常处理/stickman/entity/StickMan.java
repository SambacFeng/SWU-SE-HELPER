package exp5.stickman.entity;

import java.io.BufferedReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

import exp5.stickman.exception.SearchRadiusException;
import exp5.stickman.exception.StickmanCompleteException;
import exp5.stickman.utils.MyMath;

public class StickMan {
	private Joint[] joints = new Joint[JointType.values().length];
	private Set<Stick> sticks = new HashSet<Stick>();

	public static enum JointType {
		HeadTop, HeadDown, LeftElbow, RightElbow, LeftHand, RightHand, Waist, LeftKnee, RightKnee, LeftFoot, RightFoot
	}// 用起名的方式代替给各个关节编号的方式

	// 基于身高和腰部位置初始化
	public StickMan(double waistX, double waistY, double height) {
		for (int i = 0; i < joints.length; i++) {
			joints[i] = new Joint();
		}
		// 基于关节点初始化连边关系
		// ordinal是enum类的方法，返回枚举类的虚数.

		addStick(joints[JointType.HeadTop.ordinal()], joints[JointType.HeadDown.ordinal()]);
		addStick(joints[JointType.HeadDown.ordinal()], joints[JointType.LeftElbow.ordinal()]);
		addStick(joints[JointType.HeadDown.ordinal()], joints[JointType.RightElbow.ordinal()]);
		addStick(joints[JointType.LeftElbow.ordinal()], joints[JointType.LeftHand.ordinal()]);
		addStick(joints[JointType.RightElbow.ordinal()], joints[JointType.RightHand.ordinal()]);
		addStick(joints[JointType.HeadDown.ordinal()], joints[JointType.Waist.ordinal()]);
		addStick(joints[JointType.Waist.ordinal()], joints[JointType.LeftKnee.ordinal()]);
		addStick(joints[JointType.Waist.ordinal()], joints[JointType.RightKnee.ordinal()]);
		addStick(joints[JointType.LeftKnee.ordinal()], joints[JointType.LeftFoot.ordinal()]);
		addStick(joints[JointType.RightKnee.ordinal()], joints[JointType.RightFoot.ordinal()]);

		try (BufferedReader br = Files.newBufferedReader(Paths.get("res/jointPosition.csv"))) {
			// CSV文件的分隔符
			String DELIMITER = ",";
			// 按行读取
			String line;
			while ((line = br.readLine()) != null) {
				// 分割，0为关节名，1为横坐标，2为纵坐标
				String[] columns = line.split(DELIMITER);
				// 使用分割开的三个数据更新关节坐标
				joints[JointType.valueOf(columns[0]).ordinal()].update(Double.parseDouble(columns[1]),
						Double.parseDouble(columns[2]));
			}
		} catch (IOException ex) {
			ex.printStackTrace();
		}

//		joints[JointType.Waist.ordinal()].update(waistX, waistY);
//		joints[JointType.HeadDown.ordinal()].update(waistX, waistY - 0.3 * height);
//		joints[JointType.HeadTop.ordinal()].update(waistX, waistY - 0.4 * height);
//		joints[JointType.LeftKnee.ordinal()].update(waistX, waistY + 0.3 * height);
//		joints[JointType.LeftFoot.ordinal()].update(waistX, waistY + 0.6 * height);
//		joints[JointType.RightKnee.ordinal()].update(waistX, waistY + 0.3 * height);
//		joints[JointType.RightFoot.ordinal()].update(waistX, waistY + 0.6 * height);
//		joints[JointType.LeftElbow.ordinal()].update(waistX - 0.2 * height, waistY - 0.3 * height);
//		joints[JointType.LeftHand.ordinal()].update(waistX - 0.4 * height, waistY - 0.3 * height);
//		joints[JointType.RightElbow.ordinal()].update(waistX + 0.2 * height, waistY - 0.3 * height);
//		joints[JointType.RightHand.ordinal()].update(waistX + 0.4 * height, waistY - 0.3 * height);

		if (isComplete()) {
			throw new StickmanCompleteException("火柴人不完整！");
		}

	}

	public boolean isComplete() {
		return (sticks.size() != 10 || joints.length != 11
				|| !(existStick(joints[JointType.HeadTop.ordinal()], joints[JointType.HeadDown.ordinal()])
						&& existStick(joints[JointType.HeadDown.ordinal()], joints[JointType.LeftElbow.ordinal()])
						&& existStick(joints[JointType.HeadDown.ordinal()], joints[JointType.RightElbow.ordinal()])
						&& existStick(joints[JointType.LeftElbow.ordinal()], joints[JointType.LeftHand.ordinal()])
						&& existStick(joints[JointType.RightElbow.ordinal()], joints[JointType.RightHand.ordinal()])
						&& existStick(joints[JointType.HeadDown.ordinal()], joints[JointType.Waist.ordinal()])
						&& existStick(joints[JointType.Waist.ordinal()], joints[JointType.LeftKnee.ordinal()])
						&& existStick(joints[JointType.Waist.ordinal()], joints[JointType.RightKnee.ordinal()])
						&& existStick(joints[JointType.LeftKnee.ordinal()], joints[JointType.LeftFoot.ordinal()])
						&& existStick(joints[JointType.RightKnee.ordinal()], joints[JointType.RightFoot.ordinal()])));
	}

	public void addStick(Joint j1, Joint j2) {
		sticks.add(new Stick(j1, j2));// 创建新的Stick
	}

	// 所有关节点坐标
	public double[][] allPointCoordinates() {
		double[][] points = new double[joints.length][2];
		for (int i = 0; i < joints.length; i++) {
			points[i][0] = joints[i].getX();
			points[i][1] = joints[i].getY();
		}
		return points;
	}

	// 返回指定关节的坐标
	public double[] point(JointType type) {
		return new double[] { joints[type.ordinal()].getX(), joints[type.ordinal()].getY() };
	}

	// 返回枝干坐标信息
	public double[][] allStickCoordinates() {
		double[][] lines = new double[sticks.size()][];
		int i = 0;
		for (Stick stick : sticks) {
			lines[i++] = stick.coordinates();
		}
		return lines;
	}

	// 空间搜索
	public Joint search(double x, double y, double radius) throws SearchRadiusException {
		if (radius >= 0) {
			Joint target = null;
			double minDist = Double.MAX_VALUE;
			for (Joint joint : joints) {
				double dist = MyMath.dist(joint.getX(), joint.getY(), x, y);
				if (dist <= radius) {
					if (dist < minDist) {
						target = joint;
						minDist = dist;
					}
				}
			}
			return target;
		} else {
			throw new SearchRadiusException("搜索半径应不小于零");
		}
	}

	// 转动
	public void rotate(Joint center, Joint rotated, double arc) {
		double x1 = rotated.getX();
		double y1 = rotated.getY();

		try {
			rotated.rotate(center, arc);
			double x;
		} catch (Exception e) {
			System.out.println(e);
		}

		double dx = rotated.getX() - x1;
		double dy = rotated.getY() - y1;

		// 相邻节点平移
		move(dx, dy, allConnectedJoints(rotated, center));
	}

	// 递归获取除某节点之外的能联通当前节点的节点
	public Set<Joint> allConnectedJoints(Joint target, Joint excluded) {
		Set<Joint> set = new HashSet<Joint>();

		for (Stick stick : sticks) {
			Joint n = stick.neighbour(target);
			if (n != null) // 若邻居不为空，则添加
				set.add(n);
		}
		set.remove(excluded);

		Joint[] a = new Joint[set.size()];
		set.toArray(a);
		for (Joint j : a) {
			set.addAll(allConnectedJoints(j, target));
		}
		return set;
	}

	// 平移整个火柴人
	public void move(double dx, double dy) {
		move(dx, dy, joints);
	}

	// 平移目标关节
	public void move(double dx, double dy, Joint[] joints) {
		for (Joint joint : joints) {
			joint.update(joint.getX() + dx, joint.getY() + dy);
		}
	}

	public void move(double dx, double dy, Set<Joint> set) {
		Joint[] joints = new Joint[set.size()];
		set.toArray(joints);
		move(dx, dy, joints);
	}

	// 判断是否存在连接两个关节的枝干
	public boolean existStick(Joint j1, Joint j2) {
		Stick stick = new Stick(j1, j2);
		for (Stick s : sticks) {
			if (s.equals(stick)) {
				return true;
			}
		}
		return false;
	}

}
