package exp.exp4;

import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.application.Application;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.scene.Cursor;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.*;
import javafx.scene.image.Image;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.stage.FileChooser;
import javafx.stage.FileChooser.ExtensionFilter;
import javafx.stage.Stage;
import javafx.util.Duration;

import java.io.File;
import java.nio.file.Paths;

public class GIFApp extends Application {
    // 字幕位置以及字号
    double textX = 50;
    double textY = 50;
    int textSizeInt = 32;


    Frame[] frames = null;
    String[] texts = null;
    VBox textParent = null;
    int time = 100;
    boolean playing = false;


    @Override
    public void start(Stage primaryStage) throws Exception {
        // 页面宽高
        double viewWidth = 680;
        double viewHeight = 400;

        // 读写器
        IGIFReader reader = new GIFReader();
        IGIFWriter writer = new GIFWriter();

        // 总布局
        SplitPane layout = new SplitPane();

        // 展示区与文本添加区域布局
        VBox viewLayout = new VBox();
        VBox textLayout = new VBox();

        // 文件选择区域
        HBox fileLayout = new HBox();
        fileLayout.setPadding(new Insets(10));
        Label label = new Label("文件：");
        label.setFont(new Font(16));
        TextField filePath = new TextField();
        filePath.setEditable(false);
        filePath.setPrefWidth(viewWidth * 0.8);
        Button browse = new Button("浏览..");
        fileLayout.getChildren().addAll(label, filePath, browse);
        HBox.setMargin(filePath, new Insets(0, 10, 0, 10));
        FileChooser fileChooser = new FileChooser();
        fileChooser.setInitialDirectory(new File(".")); // 设置默认打开位置为当前程序根路径
        fileChooser.setTitle("选择动态图片");
        fileChooser.getExtensionFilters().addAll(new ExtensionFilter("动图", "*.gif"));

        // 画布区域
        Canvas canvas = new Canvas(viewWidth, viewHeight);
        GraphicsContext gc = canvas.getGraphicsContext2D();
        HBox playLayout = new HBox();
        Slider slider = new Slider();
        slider.setShowTickMarks(true);
        slider.setShowTickLabels(true);
        slider.setBlockIncrement(1);
        slider.setMajorTickUnit(1);
        slider.setPrefWidth(viewWidth * 0.9);
        Button playBtn = new Button("播放");
        playLayout.getChildren().addAll(slider, playBtn);
        VBox.setMargin(canvas, new Insets(10, 10, 10, 10));


        // 字幕添加区域
        Button addTextBtn = new Button("添加字幕");
        addTextBtn.setFont(new Font(16));
        addTextBtn.setPrefWidth(130);
        VBox.setMargin(addTextBtn, new Insets(10, 10, 10, 10));
        ScrollPane scrp = new ScrollPane();
        textParent = new VBox();
        scrp.setContent(textParent);
        Button saveBtn = new Button("导出动态图片");
        saveBtn.setPrefWidth(130);
        saveBtn.setFont(new Font(16));
        VBox.setMargin(saveBtn, new Insets(10, 10, 10, 10));
        // 颜色选择器
        Label label1 = new Label("请选择字幕颜色: ");
        ColorPicker colorPicker = new ColorPicker();
        VBox.setMargin(colorPicker, new Insets(10, 10, 10, 10));
        colorPicker.setValue(Color.RED);
        // 字号设置
        Label label2 = new Label("请设置字号: ");
        TextField textSize = new TextField();
        textSize.setText("32");
        textSize.setPrefWidth(50);
        textSizeInt = Integer.parseInt(textSize.getText());

        // 布局组合
        viewLayout.getChildren().addAll(fileLayout, canvas, playLayout);
        textLayout.getChildren().addAll(label1, colorPicker, label2, textSize, addTextBtn, scrp, saveBtn);
        layout.getItems().addAll(viewLayout, textLayout);


        // 单击按钮选择文件路径
        browse.setOnAction(e -> {
            File selectedFile = fileChooser.showOpenDialog(primaryStage);
            if (selectedFile != null) {
                filePath.setText(selectedFile.getAbsolutePath());
                frames = reader.read(selectedFile.getAbsolutePath());
                texts = new String[frames.length];
                // 获取Gif的宽高，并修改窗口宽高
                gc.drawImage(frames[0].getImage(), 0, 0, frames[0].getWidth(), frames[0].getHeight());
                canvas.setWidth(frames[0].getWidth());
                canvas.setHeight(frames[0].getHeight());
                viewLayout.setPrefWidth(frames[0].getWidth());
                layout.setPrefWidth(frames[0].getWidth() * 1.3);
                slider.setMax(frames.length - 1);
                slider.setValue(0);
            }
        });

        // 添加字幕编辑模块
        addTextBtn.setOnAction(e -> {
            TextPane tp = new TextPane(textParent);
            tp.setOnInputMethodTextChanged(te -> updateText());
            textParent.getChildren().add(tp);
            textSizeInt = Integer.parseInt(textSize.getText());
            // 渲染
            Render.rendering(canvas, frames[0], texts[0], textX, textY, colorPicker.getValue(), textSizeInt);
        });


        // 滑动查看每帧图片
        slider.valueProperty().addListener(new ChangeListener<Number>() {
            @Override
            public void changed(ObservableValue<? extends Number> arg0, Number oldValue, Number newValue) {
                if (frames != null) {
                    int i = newValue.intValue();
                    Render.rendering(canvas, frames[i], texts[i], textX, textY, colorPicker.getValue(), textSizeInt);
                }
            }
        });

        // 播放动态图片
        playBtn.setOnAction(e -> {
            textSizeInt = Integer.parseInt(textSize.getText()); // 更新字体大小
            if (frames != null && !playing) {
                updateText();
                Timeline tl = new Timeline();
                tl.setCycleCount(frames.length);
                tl.getKeyFrames().add(new KeyFrame(Duration.millis(time), new EventHandler<ActionEvent>() {
                    int i = 0;
                    @Override
                    public void handle(ActionEvent arg0) {
                        slider.setValue(i);
                        Render.rendering(canvas, frames[i], texts[i], textX, textY, colorPicker.getValue(), textSizeInt);
                        i++;
                        if (i < frames.length) {
                            time = frames[i].getDelay();
                        }
                    }
                }));
                tl.play();
                playing = true;
                tl.setOnFinished(fe -> {
                    slider.setValue(0);
                    Render.rendering(canvas, frames[0], texts[0], textX, textY, colorPicker.getValue(), textSizeInt);
                    playing = false;
                });
            }
        });

        // 导出动态图片
        saveBtn.setOnAction(e -> {
            if (frames != null) {
                String fileName = filePath.getText().replaceAll(".gif", "_new.gif");
                System.out.println("导出路径: " + fileName);
                Frame[] output = new Frame[frames.length];
                textSizeInt = Integer.parseInt(textSize.getText()); // 更新字体大小
                for (int i = 0; i < frames.length; i++) {
                    Image img = Render.rendering(canvas, frames[i], texts[i], textX, textY, colorPicker.getValue(), textSizeInt);
                    assert img != null;
                    output[i] = new Frame(img, frames[i].getDelay());
                }
                // 弹框，显示
                Alert alert = new Alert(Alert.AlertType.INFORMATION);
                alert.setTitle("保存成功");
                alert.setHeaderText("导出路径");
                alert.setContentText(fileName);
                alert.showAndWait();
                writer.write(output, fileName);
            }else{
                // 弹框，显示
                Alert alert = new Alert(Alert.AlertType.ERROR);
                alert.setTitle("保存失败");
                alert.setHeaderText("未选择图片");
                alert.showAndWait();
            }
        });

        // 拖动字体
        canvas.setCursor(Cursor.MOVE);
        canvas.addEventHandler(MouseEvent.MOUSE_DRAGGED, event -> {
            textX = event.getX();
            textY = event.getY();
            textSizeInt = Integer.parseInt(textSize.getText()); // 更新字体大小
            Render.rendering(canvas, frames[0], texts[0], textX, textY, colorPicker.getValue(), textSizeInt);
        });

        Scene scene = new Scene(layout, 860, 500);
        primaryStage.setScene(scene);
        primaryStage.setResizable(false);
        primaryStage.getIcons().add(new Image(Paths.get("bin/images/res/gif.png").toUri().toString()));
        primaryStage.setTitle("添加动图字幕");
        primaryStage.show();
    }


    public void updateText() {
        if (frames != null) {
            texts = new String[frames.length];
            for (Node tp : textParent.getChildren()) {
                TextPane temp = (TextPane) tp;
                int start = Integer.parseInt(temp.getStart().getText());
                int end = Integer.parseInt(temp.getEnd().getText());
                // 如果超出范围
                if (start < 0 || end > frames.length) {
                    // 弹框，显示
                    Alert alert = new Alert(Alert.AlertType.ERROR);
                    alert.setTitle("错误");
                    alert.setHeaderText("帧范围错误");
                    alert.showAndWait();
                } else {
                    // 弹框，显示
                    Alert alert = new Alert(Alert.AlertType.INFORMATION);
                    alert.setTitle("成功");
                    alert.setHeaderText("添加字幕成功");
                    alert.setContentText("从第 " + start + " 帧到第 " + end + " 帧\n添加字幕：" + temp.getContent().getText());
                    alert.showAndWait();
                    for (int i = start; i <= end; i++) {
                        texts[i] = temp.getContent().getText();
                    }
                }
            }
        }
    }


    public static void main(String[] args) {
        launch(args);
    }

}
