package lab;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

/**
 * @author Jeavie
 * Date created: 8/7/18
 * @version 0.1
 */

public class Diary extends Application {

    /**
     * main method
     * @param args
     */

    public static void main(String[] args) {
        launch(args);
    }

    /**
     * start showing default scene
     * @param primaryStage is the main stage
     * */

    @Override
    public void start(Stage primaryStage) throws Exception{
        Parent root = FXMLLoader.load(getClass().getResource("login/login.fxml"));
        Scene scene = new Scene(root);
        primaryStage.setTitle("Diary");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

}