module numerik {
    requires javafx.controls;
    requires javafx.fxml;

    opens numerik to javafx.fxml;
    exports numerik;
}
