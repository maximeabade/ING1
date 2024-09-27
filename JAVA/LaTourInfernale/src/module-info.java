module LaTourInfernale {
	requires transitive javafx.graphics;
	requires java.desktop;
	requires javafx.controls;
	requires javafx.base;
	requires javafx.fxml;
	requires javafx.media;
	opens com.LaTourInfernale to javafx.fxml;
	exports com.LaTourInfernale to javafx.graphics;
}