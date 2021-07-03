package exp.exp4;

import javafx.scene.SnapshotParameters;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.image.Image;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;

public class Render {
    public static Image rendering(Canvas canvas, Frame f, String text, double textX, double textY, Color textColor, int textSize) {
        System.out.println(textX);  // 监视字幕位置
        if (f != null) {
            GraphicsContext gc = canvas.getGraphicsContext2D();
            gc.drawImage(f.getImage(), 0, 0, canvas.getWidth(), canvas.getHeight());
            if (text != null) {
                gc.save();
                gc.setFill(textColor);
                gc.setStroke(Color.WHITE);
                gc.setFont(new Font(textSize));
                gc.setLineWidth(2.0);
                gc.strokeText(text, textX, textY);
                gc.fillText(text, textX, textY);
                gc.restore();
            }
            SnapshotParameters sp = new SnapshotParameters();
            return canvas.snapshot(sp, null);
        }
        return null;
    }


}
