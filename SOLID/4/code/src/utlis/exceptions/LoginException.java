package utlis.exceptions;

import javafx.scene.layout.AnchorPane;
import javafx.stage.Stage;
import utlis.Toast;

import java.util.logging.Logger;

/**
 * @author Jeavie
 * Date created: 8/16/18
 * @version 0.1
 */

public class LoginException extends Exception {

    /**
     * @param log to show message in logs
     */

    private static Logger log = Logger.getLogger(LoginException.class.getName());

    /**
     * constructor
     * @param anchorPane identifies pane where Toast should be displayed
     */

    public LoginException(AnchorPane anchorPane) {
        log.info("Sign in failed");
        Stage stage = (Stage) anchorPane.getScene().getWindow();
        Toast.makeText(stage, "Failed");
    }

}

