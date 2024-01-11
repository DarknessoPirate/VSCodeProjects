package Reszta;
import javax.swing.JFrame;
import javax.swing.JLabel;
import java.awt.FlowLayout;

public class Label {
    private static void createAndShowGUI() {
        // Tworzymy ramkę (JFrame) i ustawiamy podstawowe właściwości
        JFrame frame = new JFrame("Hello World Swing");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        // Tworzymy etykietę (JLabel) z tekstem "Hello World"
        JLabel label = new JLabel("Hello World");
        
        // Dodajemy etykietę do ramki

        frame.getContentPane().add(label);
        frame.setLayout(new FlowLayout(FlowLayout.LEFT, 150, 50));
        frame.setSize(300, 200);
        frame.setVisible(true);
    }

    public static void main(String[] args) {
                createAndShowGUI();
    }
}
