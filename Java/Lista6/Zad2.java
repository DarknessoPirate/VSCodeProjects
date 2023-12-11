import java.lang.Math.*;
class Zad2{

    public static double obliczPole(double a){
        double pole = a*a*Math.sqrt(3)/4;
        System.out.printf("Pole rownobocznego: %f", pole);
        return pole;
    }

    public static double obliczPole(double a, double h){
        double pole = a*h/2;
        System.out.printf("Pole prostokatnego: %f", pole);
        return pole;
    }
    public static double obliczPole(double a, double b, double c){
        double p = (a+b+c)/2;
        double pole = Math.sqrt(p*(p-a)*(p-b)*(p-c));
         System.out.printf("Pole roznobocznego: %f", pole);
        return pole;
    }
    public static void main(String[] args){
        double a = obliczPole(3,4,6);
        double b = obliczPole(3,4);
        double c = obliczPole(3);
    }

}