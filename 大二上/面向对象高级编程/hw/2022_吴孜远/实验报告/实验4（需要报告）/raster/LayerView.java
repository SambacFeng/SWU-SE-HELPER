package raster;

import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.paint.Color;

public class LayerView extends Canvas{
	private int gap = 5;
	private double cellSize;
	
	public LayerView(int width, int height, double cellSize) {
		this.setWidth(width * cellSize + 2 * gap);
		this.setHeight(height * cellSize + 2 * gap);
		setCellSize(cellSize);
	}
	
	// 渲染标记
	public void render(Raster r) {
		GraphicsContext gc = this.getGraphicsContext2D();
		gc.clearRect(0, 0, this.getWidth(), this.getHeight()); // 清除
		gc.setLineWidth(10);
		gc.setFill(Color.BLACK);
		gc.fillRect(gap, gap, this.getWidth() - 2 * gap, this.getHeight() - 2 * gap);
		gc.setFill(Color.YELLOW);
		int[][] values = r.copyValues();
		for(int y = 0; y < values.length; y ++) {
			for(int x = 0; x < values[y].length; x ++) {
				if(values[y][x] == 1) {
					gc.fillRect((x + r.getStartX()) * getCellSize(), (y + r.getStartY()) * getCellSize(), getCellSize(), getCellSize());
				}
			}
		}
	}

	public double getCellSize() {
		return cellSize;
	}

	public void setCellSize(double cellSize) {
		this.cellSize = cellSize;
	}
}
