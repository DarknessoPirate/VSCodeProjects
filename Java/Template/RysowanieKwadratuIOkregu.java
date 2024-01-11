import javax.swing.*;
import java.awt.*;

class MyPanel extends JPanel {
    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        setBackground(Color.RED);

        // Rysowanie kwadratu
        int kwadratRozmiar = 200;
        int kwadratX = (getWidth() - kwadratRozmiar) / 2;
        int kwadratY = (getHeight() - kwadratRozmiar) / 2;
        g.setColor(Color.BLACK);
        g.drawRect(kwadratX, kwadratY, kwadratRozmiar, kwadratRozmiar);

        // Rysowanie przekątnej kwadratu
        g.drawLine(kwadratX, kwadratY + kwadratRozmiar, kwadratX + kwadratRozmiar, kwadratY);

        // Rysowanie okręgu wewnątrz kwadratu
        int okragRozmiar = kwadratRozmiar;
        int okragX = kwadratX + (kwadratRozmiar - okragRozmiar) / 2;
        int okragY = kwadratY + (kwadratRozmiar - okragRozmiar) / 2;
        g.drawOval(okragX, okragY, okragRozmiar, okragRozmiar);

        // Rysowanie okręgu wokół kwadratu
        int okragWokolRozmiar = kwadratRozmiar + 150;
        int okragWokolX = (getWidth() - okragWokolRozmiar) / 2;
        int okragWokolY = (getHeight() - okragWokolRozmiar) / 2;
        g.drawOval(okragWokolX, okragWokolY, okragWokolRozmiar, okragWokolRozmiar);
    }
}

public class RysowanieKwadratuIOkregu extends JFrame {

    public RysowanieKwadratuIOkregu() {
        setTitle("Rysowanie Kwadratu i Okręgu");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(600, 600);
        setLocationRelativeTo(null);

        MyPanel panel = new MyPanel();
        add(panel);

        setVisible(true);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(RysowanieKwadratuIOkregu::new);
    }
}
