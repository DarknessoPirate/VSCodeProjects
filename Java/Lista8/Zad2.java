import javax.swing.*;
import java.awt.*;

public class Zad2 {
public static void main(String[] args) {
    JFrame frame = new JFrame("Frame");
    JPanel panel = new JPanel();
    Graphics g = panel.getGraphics();
    g.drawString("Dorimedd", 100, 100);
    panel.paintComponents(g);
}    
}
