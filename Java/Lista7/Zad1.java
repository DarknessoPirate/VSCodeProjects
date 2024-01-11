import pzespolone.Complex;
import przeczywiste.Real;

public class Zad1 {
   
    public static void main(String[] args) {
        Complex c1 = new Complex(2, 3);
        Complex c2 = new Complex(4,5);
        Real r1 = new Real(7);
        Real r2 = new Real(8);  
        
        System.out.println(r1.Add(r2));
        System.out.println(r1.Subtract(r2));
        System.out.println(r1.Multiply(r2));
        System.out.println(r1.Divide(r2));
        
    }
}
