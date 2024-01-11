package Reszta;
import javax.swing.*;
import java.awt.*;
import java.awt.geom.Ellipse2D;

public class Ksztalty extends JFrame {

    public void ShapesDrawing() {
        setTitle("Shapes Drawing");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(400, 400);
        setLocationRelativeTo(null);
        setVisible(true);
    }

    @Override
    public void paint(Graphics g) {
        super.paint(g);

        // Rysowanie prostokąta
        g.drawRect(50, 50, 200, 100);

        // Rysowanie elipsy zamkniętej w prostokącie
        Ellipse2D ellipse = new Ellipse2D.Double(50, 50, 200, 100);
        Graphics2D g2d = (Graphics2D) g;
        g2d.draw(ellipse);

        // Rysowanie przekątnej prostokąta
        g.drawLine(50, 50, 250, 150);

        // Rysowanie okręgu o środku w tym samym punkcie, co środek prostokąta
        int centerX = 50 + 200 / 2;
        int centerY = 50 + 100 / 2;
        int radius = 50;
        g.drawOval(centerX - radius, centerY - radius, 2 * radius, 2 * radius);
    }

    public static void main(String[] args) {

    }
}