package numerik;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.stage.Stage;


public class GaussAlgorithm extends Application {

    private static final int WIDTH = 800;
    private static final int HEIGHT = 600;
    //private static final int PADDING = 50;
    private static final int VECTOR_LENGTH = 200;
    private static Canvas canvas;
    private static GraphicsContext gc; 

    public static void main(String[] args){

        launch(args);

        /*         
        gaussianElimination(matrix);
        */
    }

    @Override
    public void start(Stage primaryStage){

        primaryStage.setTitle("Gaussian elimination visualisation");

        Pane root = new Pane();
        canvas = new Canvas(WIDTH, HEIGHT);
        gc = canvas.getGraphicsContext2D();
        root.getChildren().add(canvas);
    
        double[][] matrix = {
            {2,1,-1,8},
            {-3,-1,2,-11},
            {-2,1,2,-3}
        };

        draw3DCoordinateSystem();

//        drawMatrix(matrix);
//        gaussianElimination(matrix);

        primaryStage.setScene(new Scene(root));
        primaryStage.show();

    }


    private void draw3DCoordinateSystem(){

        gc.clearRect(0, 0, WIDTH, HEIGHT);

        /* center the canvas */
        double centerX = WIDTH / 2;
        double centerY = HEIGHT / 2;

        /* Axes lengths */
        double axisLength = 200;

        /* 3D points for the axes */
        double[][] axes = {
            {axisLength, 0, 0}, // x axis
            {0, axisLength, 0}, // y axis
            {0,0, axisLength}   // z axis
        };

        /* coloring the axes */
        Color[] colors = {Color.RED, Color.GREEN, Color.BLUE};

        /* drawing axes */
        for(int i = 0; i < axes.length; i++){
            double[] axis = axes[i];
            double[] projected = project3DTo2D(axis[0], axis[1], axis[2]);
            gc.setStroke(colors[i]);
            gc.strokeLine(centerX, centerY, centerX + projected[0], centerY - projected[1]);

        }
    }

    private double[] project3DTo2D(double x, double y, double z){

        double scale = 1;
        double projectedX = x * scale;
        double projectedY = y * scale - z * scale * 0.5;
        return new double []{projectedX, projectedY};
    }


    public static void gaussianElimination(double[][] matrix){

        int n = matrix.length;

        /*forward elimination*/
        for (int i = 0; i<n; i++){

            /* search for maxRow in current column */

            double maxEl = Math.abs(matrix[i][i]);
            int maxRow = i;
            for (int k = i; k<n; k++){
                if (Math.abs(matrix[k][i]) > maxEl){
                    maxEl = Math.abs(matrix[k][i]);
                    maxRow = k;
                }
            }

            /* swap max row with current row */

            double[] temp = matrix[maxRow];
            matrix[maxRow] = matrix[i];
            matrix[i] = temp;
            
            drawMatrix(matrix);
            pause();

            /* elimination step */

            for (int k = i+1; k<n; k++){
                double c = -matrix[k][i] / matrix[i][i];
                for (int j = i; j<n+1; j++){
                    if(i==j){
                        matrix[k][j] = 0;
                    } else {
                        matrix[k][j] += c * matrix[i][j]; 
                    }
                }
            }
        }

        /* backwards substitution */

        double[] solution = new double[n];
        for(int i = n-1; i>=0; i--){
            solution[i] = matrix[i][n] / matrix[i][i];
            for(int k = i-1;k>=0; k--){
                matrix[k][n] -= matrix[k][i] * solution[i];
            }
        }

        /* print solution */

        System.out.println("Solution:");
        for(int i = 0; i<n;i++){
            System.out.println("x" + (i+1) + " = " + solution[i]);
        }
    }

    public static void drawMatrix(double[][] matrix){
        gc.clearRect(0,0,WIDTH,HEIGHT);
        gc.setStroke(Color.BLACK);
        gc.setLineWidth(2);

        for(int i = 0; i<matrix.length; i++){
            double x = WIDTH / 2 + matrix[i][0] * VECTOR_LENGTH;
            double y = HEIGHT / 2 - matrix[i][1] * VECTOR_LENGTH;
            gc.strokeLine(WIDTH / 2, HEIGHT / 2, x, y);
        }
    }

    private static void pause(){
        try {
            Thread.sleep(1000);
        } catch (InterruptedException e){
            e.printStackTrace();
        }
    }
}
