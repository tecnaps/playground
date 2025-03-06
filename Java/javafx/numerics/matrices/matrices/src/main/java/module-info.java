module com.numerics {
    requires javafx.controls;
    requires javafx.fxml;

    opens com.numerics to javafx.fxml;
    exports com.numerics;
}
