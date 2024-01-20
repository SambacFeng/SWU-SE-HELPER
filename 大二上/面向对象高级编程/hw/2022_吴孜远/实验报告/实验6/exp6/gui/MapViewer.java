package exp6.gui;

import java.util.Map;
import java.util.HashMap;

import exp6.biz.Controller;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.image.Image;
import javafx.scene.input.MouseButton;
import javafx.scene.paint.Color;

public class MapViewer extends Canvas{
	private Controller controller;
	private double cellSize;
	private double[] selectedFrame = new double[4];
	private Map<String, Image> code2Image = new HashMap<String, Image>();
	double dragStartX = -1, dragStartY = -1;
	
	public MapViewer(Controller c, double cellSize){
		controller = c;
		setCellSize(cellSize);
		
		int h = controller.getViewArea().getHeight();
		int w = controller.getViewArea().getWidth();
		this.setWidth(w * cellSize);
		this.setHeight(h * cellSize);
		
		// 鼠标拖动事件
		this.setOnMouseDragged(e -> {
			if(dragStartX < 0) {
				dragStartX = e.getX();
				dragStartY = e.getY();
			}else {
				double endX = e.getX();
				double endY = e.getY();
				selectedFrame[0] = Math.min(dragStartX, endX);
				selectedFrame[1] = Math.min(dragStartY, endY);
				selectedFrame[2] = Math.abs(dragStartX - endX);
				selectedFrame[3] = Math.abs(dragStartY - endY);
				controller.select((int)(dragStartX / cellSize), (int)(dragStartY / cellSize), (int)(endX / cellSize), (int)(endY / cellSize));
			}
		});
		
		// 按键移动视区
		this.setOnKeyPressed(e -> {
			switch(e.getCode()) {
				case UP:controller.viewMove(0, 1);break;
				case DOWN:controller.viewMove(0, -1);break;
				case LEFT:controller.viewMove(1, 0);break;
				case RIGHT:controller.viewMove(-1, 0);break;
				default:;
			}
			this.render();
		});
		
		// 鼠标释放
		this.setOnMouseReleased(e -> {
			dragStartX = -1;
			dragStartY = -1;
			for(int i = 0; i < selectedFrame.length; i++) {
				selectedFrame[i] = 0;
			}
		});
		
		// 行走和聚焦
		this.setOnMousePressed(e -> {
			this.requestFocus(); // 聚焦当前Viewer以监听按键事件
			if(e.getButton() == MouseButton.SECONDARY) {
				int x = (int) (e.getX() / cellSize);
				int y = (int) (e.getY() / cellSize);
				controller.moveTo(x, y);
			}
			if(e.getButton() == MouseButton.PRIMARY) {
				int x = (int) (e.getX() / cellSize);
				int y = (int) (e.getY() / cellSize);
				controller.selectSingle(x, y);
			}
		});
	}
	
	public void put(String code, Image image) {
		code2Image.put(code, image);
	}
	
	public void render() {
		GraphicsContext gc = this.getGraphicsContext2D();
		gc.clearRect(0, 0, this.getWidth(), this.getHeight());
		
		
		int[][] codes = controller.codes();
		
		for(int x = 0; x < codes.length; x++) {
			for(int y = 0; y < codes[x].length; y++) {
				gc.drawImage(code2Image.get("map" + codes[x][y]), x * cellSize, y * cellSize, cellSize, cellSize);
			}
		}
		
		gc.setFill(Color.BLACK);
		int[][] balls = controller.balls();
		for(int[] b : balls) {
			gc.drawImage(code2Image.get("ball" + b[2]), b[0] * cellSize, b[1] * cellSize, cellSize, cellSize);
			//gc.fillOval(r[0] * cellSize, r[1] * cellSize, cellSize, cellSize);
		}
		gc.setStroke(Color.YELLOW);
		int[][] selected = controller.selectedBalls();
		for(int[] s : selected) {
			gc.strokeRect(s[0] * cellSize, s[1] * cellSize, cellSize, cellSize);
		}
		gc.strokeRect(selectedFrame[0],selectedFrame[1],selectedFrame[2],selectedFrame[3]);
	}

	public double getCellSize() {
		return cellSize;
	}

	public void setCellSize(double cellSize) {
		this.cellSize = cellSize;
	}
	
	
}
