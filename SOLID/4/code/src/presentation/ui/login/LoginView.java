package presentation.ui.login;

import data.UserModel;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;

import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;
import javafx.scene.layout.AnchorPane;
import javafx.stage.Stage;
import utlis.exceptions.LoginException;

import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;
import java.util.logging.Logger;

/**
 * @author Jeavie
 * Date created: 8/7/18
 * @version 0.1
 */

public class LoginView implements Initializable {

    private UserModel userModel;

    @FXML AnchorPane mainPane;
    @FXML TextField loginField;
    @FXML PasswordField passwordField;
    @FXML Button signInButton, signUpButton;

    private static Logger log = Logger.getLogger(LoginView.class.getName());

    @FXML
    private void logIn (ActionEvent event) throws IOException, LoginException {

        UserModel userModel = new UserModel("alena", "m");
        if (userModel.getLogin().equals(loginField.getText()) && userModel.getPassword().equals(passwordField.getText())){
            log.info("Success");
            Parent parent = FXMLLoader.load(getClass().getResource("/presentation/ui/diary/diary.fxml"));
            Scene scene = new Scene(parent);
            Stage appWindow = (Stage) ((Node) event.getSource()).getScene().getWindow();
            appWindow.hide();
            appWindow.setScene(scene);
            appWindow.show();
        } else throw new LoginException(mainPane);
    }

    @Override
    public void initialize(URL location, ResourceBundle resources) {
        signInButton.setOnAction(event -> {
            try {
                logIn(event);
            } catch (IOException e) {
                e.printStackTrace();
            } catch (LoginException e) {

            }
        });
    }

}
