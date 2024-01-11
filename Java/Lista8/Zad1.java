import javax.swing.*;

public class Zad1{
public static void main(String[] args){
    JFrame frame = new JFrame("Frame");
    frame.setLayout(null);
    frame.setSize(300,400);
    JLabel t = new JLabel("Tekst");
    frame.add(t);
    t.setBounds(100, 100, 200, 200);

    frame.setVisible(true);
}
}