package exp5.stickman.gui;


import exp5.stickman.biz.Controller;
import exp5.stickman.utils.MyMath;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.input.MouseButton;
import javafx.scene.paint.Color;

public class StickManView extends Canvas{
	
	Controller controller;
	double dragStartX = -1, dragStartY = -1;
	
	public StickManView(Controller c){
		controller = c;
		// 鼠标拖动事件
		this.setOnMouseDragged(e -> {	
			if(dragStartX < 0) {
				dragStartX = e.getX();
				dragStartY = e.getY();
			}else {
				double endX = e.getX();
				double endY = e.getY();
				controller.move(dragStartX, dragStartY, endX, endY);
				dragStartX = endX;
				dragStartY = endY;
				this.render();
			}	
		});
		
		// 鼠标释放
		this.setOnMouseReleased(e -> {
			dragStartX = -1;
			dragStartY = -1;
		});
		
		// 鼠标右键事件
		this.setOnMouseClicked(e -> {
			if(e.getButton() == MouseButton.SECONDARY) {
				controller.fix();
				this.render();
			}
		});
		
		// 鼠标移动事件
		this.setOnMouseMoved(e -> {
			controller.focus(e.getX(), e.getY());
			this.render();
		});
	}
	
	public void render() {
		GraphicsContext gc = this.getGraphicsContext2D();
		gc.clearRect(0, 0, this.getWidth(), this.getHeight());

		gc.setFill(Color.RED);
		gc.setStroke(Color.RED);
		gc.setLineWidth(16.0);
		
		double[][] lines = controller.getLines();
		drawAllLines(lines);
		
		//double[][] points = controller.getPoints();
		//drawAllPoints(points, 10);
		
		double[][] head = controller.getHead();
		double[] headCenter = new double[] {(head[0][0] + head[1][0]) / 2, (head[0][1] + head[1][1]) / 2 - 10};
		drawPoint(headCenter, MyMath.dist(head[0][0], head[0][1], head[1][0], head[1][1]));
		
		gc.setFill(Color.YELLOW);
		drawPoint(controller.getFocused(), 20);
		gc.setFill(Color.GREY);
		drawPoint(controller.getFixed(), 20);
	}
	
	
	public void drawLine(double[] line) {
		GraphicsContext gc = this.getGraphicsContext2D();
		gc.strokeLine(line[0], line[1], line[2], line[3]);
	}
	public void drawAllLines(double[][] lines) {
		for(double[] line : lines) {
			drawLine(line);
		}
	}
	
	public void drawPoint(double[] p, double radius) {
		if(p != null) {
			GraphicsContext gc = this.getGraphicsContext2D();
			gc.fillOval(p[0] - radius / 2, p[1] - radius / 2, radius, radius);
		}
	}
	
	public void drawAllPoints(double[][] points, double radius) {
		for(int i = 0; i < points.length; i++) {
			drawPoint(points[i], radius);
		}
	}
	
}
