package week16;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.*;

public class MapPane extends Pane {
	public final static int CELL_SIZE = 64;
	
	private Image[] icons;
	
	private ImageView[][] map;
	
	private Man man;
	
	private List<ImageView> targets;
	
	private int xlength;
	private int ylength;
	
	public MapPane(Image[] iconList, File mapFile) {
		icons = iconList;
		// Load map
		this.loadMap(mapFile);
		// Set background
		Background bg = new Background(
				new BackgroundImage(
						iconList[Element.BACKGROUND],
						BackgroundRepeat.REPEAT,
						BackgroundRepeat.REPEAT,
						BackgroundPosition.DEFAULT,
						new BackgroundSize(
								BackgroundSize.AUTO,
								BackgroundSize.AUTO,
								true, true, false, false)
						)
				);
		setBackground(bg);
	}
	
	public void loadMap(File mapFile) {
		try(Scanner input = new Scanner(mapFile)){
			 // Get length information from the first line in the map file
			String[] items = input.nextLine().split(",");
			int xlen = Integer.parseInt(items[0]);
			int ylen = Integer.parseInt(items[1]);
			xlength = xlen;
			ylength = ylen;
			
			// Initialize and clear the map pane
			this.map = new ImageView[xlen][ylen];
			targets = new ArrayList<ImageView>();
			this.getChildren().clear();
			
			// Read file and add elements to the map pane
			while(input.hasNextLine()) {
				 // Get information of a element from string parsing
				items = input.nextLine().split(",");
				int x = Integer.parseInt(items[0]);
				int y = Integer.parseInt(items[1]);
				int type = Integer.parseInt(items[2]);
				
				// Create an element
				Element e = null;
				switch(type) {
					case Element.MAN: 
						e = this.man = new Man(icons[Element.MAN]);
						break;
					case Element.BOX:
						e = new Box(icons[Element.BOX]);
						break;
					case Element.WALL:
						e = new Wall(icons[Element.WALL]);
						break;
					case Element.TARGET:
						e= new Target(icons[Element.TARGET]);
						break;
					default:break;
				}
				
				// Set the position and display the element
				e.setX(x * CELL_SIZE);
				e.setY(y * CELL_SIZE);
				getChildren().add(e);
				// Add element to the logical map
				if(e instanceof Target) {
					targets.add(e);
				}else {
					this.map[x][y] = e;
				}
			}
		}catch(IOException e) {
			e.printStackTrace();
		}
	}
	
	// Judge the state of the game
	public boolean judge() {
		boolean win = true;
		for(ImageView img: targets) {//TBF
			int x = (int) (img.getX() / CELL_SIZE);
			int y = (int) (img.getY() / CELL_SIZE);
			if(!(this.map[x][y] instanceof Box)) {//TBF
				win = false;
				break;
			}
		}
		return win;
	}
	
	public void moveManUp(){
		int manX = (int) (man.getX() / CELL_SIZE);
		int manY = (int) (man.getY() / CELL_SIZE);
		if(manY > 0) {
			if(map[manX][manY - 1] == null) {
				man.up();
				map[manX][manY] = null;
				map[manX][manY - 1] = man;
			}else if(map[manX][manY - 1] instanceof Box) {
				if(manY - 1 > 0 && map[manX][manY - 2] == null) {
					Box b = (Box) map[manX][manY - 1];
					b.up(); 
					map[manX][manY - 2] = b;
					man.up();
					map[manX][manY] = null;
					map[manX][manY - 1] = man;
				}
			}//if
		}//if
	}
	
	public void moveManDown(){
		int manX = (int) (man.getX() / CELL_SIZE);
		int manY = (int) (man.getY() / CELL_SIZE);
		if(manY < ylength - 1) {
			if(map[manX][manY + 1] == null) {
				man.down();
				map[manX][manY] = null;
				map[manX][manY + 1] = man;
			}else if(map[manX][manY + 1] instanceof Box) {
				if(manY + 1 < ylength - 1 && map[manX][manY + 2] == null) {
					Box b = (Box) map[manX][manY + 1];
					b.down();
					map[manX][manY + 2] = b;
					man.down();
					map[manX][manY] = null;
					map[manX][manY + 1] = man;
				}
			}//if
		}//if
	}
	
	public void moveManLeft(){
		int manX = (int) (man.getX() / CELL_SIZE);
		int manY = (int) (man.getY() / CELL_SIZE);
		if(manX > 0) {
			if(map[manX - 1][manY] == null) {
				man.left();
				map[manX][manY] = null;
				map[manX - 1][manY] = man;
			}else if(map[manX - 1][manY] instanceof Box) {
				if(manX - 1 > 0 && map[manX - 2][manY] == null) {
					Box b = (Box) map[manX - 1][manY];
					b.left();
					map[manX - 2][manY] = b;
					man.left();
					map[manX][manY] = null;
					map[manX - 1][manY] = man;
				}
			}//if
		}//if
	}
	
	public void moveManRight(){
		int manX = (int) (man.getX() / CELL_SIZE);
		int manY = (int) (man.getY() / CELL_SIZE);
		if(manX < xlength - 1) {
			if(map[manX + 1][manY] == null) {
				man.right();
				map[manX][manY] = null;
				map[manX + 1][manY] = man;
			}else if(map[manX + 1][manY] instanceof Box) {
				if(manX + 1 < xlength - 1 && map[manX + 2][manY] == null) {
					Box b = (Box) map[manX + 1][manY];
					b.right();
					map[manX + 2][manY] = b;
					man.right();
					map[manX][manY] = null;
					map[manX + 1][manY] = man;
				}
			}//if
		}//if
	}

	
	
	
	


}
