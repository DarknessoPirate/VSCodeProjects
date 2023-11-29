import java.util.Scanner;


class Kolo{
    private double radius;
    private double side;
    private double rectangle1;
    private double rectangle2;
    private double height;
    private double pole_trojkata;
    private double pole_prostokata;
    private double pole_kola;

    void WczytajDane(){
        Scanner in = new Scanner(System.in);
        System.out.println("Podaj bok trojkata:");
        side = in.nextDouble();
        System.out.println("Podaj wysokosc trojkata:");
        height = in.nextDouble();
        System.out.println("Podaj bok 1 prostokata:");
        rectangle1 = in.nextDouble();
        System.out.println("Podaj bok 2 prostokata:");
        rectangle2 = in.nextDouble();
        System.out.println("Podaj promien kola:");
        radius = in.nextDouble();
        in.close();
    }

    void PoleTrojkata(){
        pole_trojkata = side*height/2.0;
    }

    void PoleKola(){
        pole_kola = 3.14*radius*radius;
    }

    void PoleProstokata(){
        
        pole_prostokata = rectangle1*rectangle2;
    }
    void oblicz_pole(){
        PoleKola();
        PoleProstokata();
        PoleTrojkata();
    }

    void Wyswietl_Pole(){
        System.out.printf("Pole kola: %f \n", pole_kola);
        System.out.printf("Pole prostokata: %f\n" , pole_prostokata);
        System.out.printf("Pole trojkata: %f\n",pole_trojkata);
    }

}


public class Zad2{

public static void main(String[] args) {

    Kolo k1 = new Kolo();
    k1.WczytajDane();
    k1.oblicz_pole();
    k1.Wyswietl_Pole();
}

}
