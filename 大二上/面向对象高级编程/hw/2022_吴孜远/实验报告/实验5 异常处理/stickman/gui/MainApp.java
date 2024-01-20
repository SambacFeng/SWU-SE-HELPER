package exp5.stickman.gui;

import javafx.animation.Animation;
import javafx.animation.KeyFrame;
import javafx.animation.KeyValue;
import javafx.animation.Timeline;
import javafx.application.Application;
import javafx.stage.Stage;
import javafx.util.Duration;
import javafx.scene.layout.*;
import javafx.scene.canvas.*;
import javafx.scene.control.Button;
import javafx.scene.control.ScrollPane;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.image.WritableImage;
import javafx.scene.input.MouseButton;
import javafx.scene.paint.*;
import javafx.scene.*;

import java.util.ArrayList;
import java.util.List;

import exp5.stickman.biz.Controller;
import exp5.stickman.entity.*;
import exp5.stickman.exception.SearchRadiusException;

public class MainApp extends Application{

	@Override
	public void start(Stage primaryStage) throws Exception {
		
		int thumbnailHeight = 100;
		
		StickMan man = new StickMan(250, 300, 600);
		Controller controller = new Controller(man);
		StickManView view = new StickManView(controller);
		view.setWidth(500);
		view.setHeight(800);

		VBox layout = new VBox();
		HBox imagesView = new HBox();
		ScrollPane scrollImageView = new ScrollPane(imagesView);
		scrollImageView.setMinHeight(thumbnailHeight);
		Button playBtn = new Button("播放");
		playBtn.setMinWidth(60);
		Button snapBtn = new Button("拍照");
		snapBtn.setMinWidth(60);
		HBox topLayout = new HBox();
		topLayout.getChildren().addAll(scrollImageView, snapBtn, playBtn);

		HBox downLayout = new HBox();
		ImageView imgView = new ImageView();
		imgView.setFitWidth(500);
		imgView.setFitHeight(800);
		downLayout.getChildren().addAll(view, imgView);

		layout.getChildren().addAll(topLayout,downLayout);
		
		view.render();
		
		ImageBox box = new ImageBox();
		
		snapBtn.setOnAction(e -> {
			WritableImage wi = view.snapshot(new SnapshotParameters(), null);
			box.add(wi);
			ImageView iv = new ImageView(wi);
			iv.setFitHeight(thumbnailHeight);
			iv.setFitWidth((thumbnailHeight / wi.getHeight()) * wi.getWidth());
			imagesView.getChildren().add(iv);
		});
		
		
		Scene scene = new Scene(layout);
		
		Timeline timeline = new Timeline();
		timeline.setCycleCount(Animation.INDEFINITE);
		KeyFrame kf = new KeyFrame(Duration.millis(100), e -> {
			imgView.setImage(box.get());
		});
		timeline.getKeyFrames().add(kf);
		
		playBtn.setOnAction(e -> {
			timeline.play();
		});
	

		primaryStage.setScene(scene);
		primaryStage.setResizable(false);
		primaryStage.setTitle("火柴人");
		primaryStage.show();
		
	}
	
	private class ImageBox{
		private List<Image> list = new ArrayList<Image>();
		private int current = 0;
		
		public void add(Image img) {
			list.add(img);
		}
		public Image get() {
			return list.get(current++ % list.size());
		}
	}
	
	

	public static void main(String[] args){
		launch(args);
	}
	
}
