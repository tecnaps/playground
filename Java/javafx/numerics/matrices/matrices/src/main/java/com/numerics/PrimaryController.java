package com.numerics;

import java.util.ResourceBundle;

import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.Button;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.control.TextField;
import javafx.scene.paint.Color;
import javafx.scene.Scene;
import javafx.stage.Stage;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.util.stream.Stream;

import java.net.URL;


public class PrimaryController implements Initializable {

    @FXML
    private Canvas sheet;

    private GraphicsContext gc;
    private int axeLength = 600;
    private double[] center = new double[2];
    private VBox vectorContainer;

    @Override
    public void initialize(URL location, ResourceBundle resources){


        // control window for inputs

        Stage controlWindow = new Stage();
        VBox controlElements = new VBox(10);
        Scene controlScene = new Scene(controlElements, 568, 100);
        controlWindow.setScene(controlScene);
        controlWindow.setTitle("Steuerung");
        controlWindow.show();

        vectorContainer = new VBox(10);             // contains all vectors
        Button addButton = new Button ("+");        // add vector
        Button removeButton = new Button ("-");     // remove vector
        Button drawButton = new Button("draw");     // draw vectors on canvas

        controlElements.getChildren().add(vectorContainer);
        controlElements.getChildren().add(addButton);
        controlElements.getChildren().add(removeButton);
        controlElements.getChildren().add(drawButton);


        addButton.setOnAction(event ->{
            HBox newRow = addVector(); 
            vectorContainer.getChildren().add(newRow);
        });

        removeButton.setOnAction(event->{
            if (vectorContainer.getChildren().size() > 3)
                vectorContainer.getChildren().remove(vectorContainer.getChildren().size() - 1);            
        });

        drawButton.setOnAction(event ->{
            drawVector();       // only prints the input atm

        });

                
        gc = sheet.getGraphicsContext2D();

        /* fill background black*/

        gc.setFill(Color.BLACK);
        gc.fillRect(0,0, sheet.getWidth(), sheet.getHeight());

        /* draw axes */

        drawAxes();
    }


    public void drawAxes(){

        /* determine origin */
        center[0] = sheet.getWidth() / 2;
        center[1] = sheet.getHeight() / 2;

        /* draw axes */
        gc.setStroke(Color.WHITE);
        gc.setLineWidth(2.0);
        gc.strokeLine(center[0] - axeLength / 2, center[1], center[0] + axeLength / 2, center[1]);
        gc.strokeLine(center[0], center[1] - axeLength / 2, center[0], center[1] + axeLength / 2);
        gc.strokeLine(center[0] - axeLength / 4, center[1] + axeLength / 4, center[0] + axeLength / 4, center[1] - axeLength / 4);
    }


    private HBox addVector(){ 

        /* adds a new empty vector to vectorContain aer*/
        
        HBox row = new HBox();

        for (int i = 0; i < 3; i++){
            TextField textField = new TextField();
            row.getChildren().add(textField);
        }

        return row;
    }


    public List<Vector> getVectorsFromInput() {

        /*  collects the input from all non-empty textfields in a List <Double> */

        List <Double> input = vectorContainer.getChildren().stream()
                .filter(node -> node instanceof HBox)
                .flatMap(hbox -> ((HBox) hbox).getChildren().stream())
                .filter(node -> node instanceof TextField)
                .map(node->((TextField) node).getText())
                .filter(text -> !text.isEmpty())
                .map(Double::parseDouble)
                .collect(Collectors.toList());
        input.forEach(System.out::println);        
        List <List<Double>> groupedElements = groupElements(input.stream(), 3);

        return groupedElements.stream()
                .filter(group -> group.size()== 3)
                .map(group -> new Vector(group.get(0), group.get(1), group.get(2)))
                .collect(Collectors.toList());
    }

public static <T> List<List<T>> groupElements(Stream<T> input, int groupSize) {

    /* custom collector to group the elements in input into groups of groupSize */

    /* All elements of input are first collected in a List elements
     * Next the number of groups is calculated based on the size of elements and
     *  groupSize (note: groupSize is necessary of the list contains < 3 elements)
     * Next an IntStream is created to iterate over the group indices and each index
     *  is mapped to a sublist of elements with 
     *      start index:     i*groupSize
     *      end index:       Math.min((i+1)*groupSize, elements.size())
     * Finally all sublists are collected in a List
    */

    List<T> elements = input.collect(Collectors.toList());
    int numberOfGroups = (elements.size() + groupSize -1) / groupSize;

    return IntStream.range(0, numberOfGroups)
            .mapToObj(i -> elements.subList(i * groupSize, Math.min((i+1) * groupSize, elements.size())))
            .collect(Collectors.toList());
        }
    

    public void drawVector(){

        /* function for drawing a vector*/

        printList();

        // rework below!

        //gc.setStroke(Color.BLUE);
        //gc.setLineWidth(2.0);
        //gc.strokeLine(center[0], center[1], center[0]+vector[0]+vector[2]/2, center[1]+vector[1]+vector[2]/2);

    }


    public void printList(){

        /* test method to print contents retrieved via getVectorsFromInput() */

        List<Vector> inputs = getVectorsFromInput();
        inputs.forEach(System.out::println);
    }


}
