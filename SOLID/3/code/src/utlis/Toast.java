package utlis;

import javafx.animation.KeyFrame;
import javafx.animation.KeyValue;
import javafx.animation.Timeline;
import javafx.scene.Scene;
import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import javafx.stage.Stage;
import javafx.stage.StageStyle;
import javafx.util.Duration;

public final class Toast
{
    public static void makeText(Stage ownerStage, String toastMsg)
    {
        Stage toastStage=new Stage();
        toastStage.initOwner(ownerStage);
        toastStage.setResizable(false);
        toastStage.initStyle(StageStyle.TRANSPARENT);

        toastStage.setWidth(93.0);
        toastStage.setHeight(25.0);
        double centerX = ownerStage.getX() + ownerStage.getWidth() / 2 - toastStage.getWidth() / 2;
        double centerY = ownerStage.getY() + ownerStage.getHeight() / 2 - toastStage.getHeight() / 2;
        toastStage.setX(centerX);
        toastStage.setY(centerY + toastStage.getHeight() * 5);

        Text text = new Text(toastMsg);
        text.setFont(Font.font("Raleway", 13));
        text.setFill(Color.WHITE);

        StackPane root = new StackPane(text);
        root.setStyle("-fx-background-radius: 22; -fx-background-color: rgba(255, 255, 255, 0.25); -fx-padding: 10px;");
        root.setOpacity(0);

        Scene scene = new Scene(root);
        scene.setFill(Color.TRANSPARENT);
        toastStage.setScene(scene);
        toastStage.show();

        Timeline fadeInTimeline = new Timeline();
        // 500 - 0.5 sec appears
        KeyFrame fadeInKey1 = new KeyFrame(Duration.millis(500), new KeyValue (toastStage.getScene().getRoot().opacityProperty(), 1));
        fadeInTimeline.getKeyFrames().add(fadeInKey1);
        fadeInTimeline.setOnFinished((ae) ->
                new Thread(() -> {
                    try
                    {
                        //1 sec lasts
                        Thread.sleep(1000);
                    }
                    catch (InterruptedException e)
                    {
                        e.printStackTrace();
                    }
                    Timeline fadeOutTimeline = new Timeline();
                    // 0.5 sec hides
                    KeyFrame fadeOutKey1 = new KeyFrame(Duration.millis(500), new KeyValue (toastStage.getScene().getRoot().opacityProperty(), 0));
                    fadeOutTimeline.getKeyFrames().add(fadeOutKey1);
                    fadeOutTimeline.setOnFinished((aeb) -> toastStage.close());
                    fadeOutTimeline.play();
                }).start());
        fadeInTimeline.play();
    }
}
