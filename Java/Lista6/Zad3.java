import java.lang.Math.*;
class Real{
    protected double real;

    public Real(double r){
        real = r;
    }
    public double modul(){
        double mod = Math.sqrt(real*real);
        System.out.printf("Modul liczby rzeczywistej: %f\n", mod);
        return mod;
    }
}

class Complex extends Real{
    double imag;
    public Complex(double r, double i){
        super(r);
        imag = i;
    }

    public double modul(){
        double mod = Math.sqrt(real*real+imag*imag);
        System.out.printf("Modul liczby zespolonej: %f\n", mod);
        return mod;
    }
}
public class Zad3 {
    public static void main(String[] args) {
     Real a = new Real(-7);
     a.modul();
     Complex c = new Complex(-7,4);
     c.modul();   
    }
}
