import java.lang.Math.*;
import java.util.*;



class Zad1{

public static double modul(double r){
    return Math.sqrt(r*r);
}

public static double modul(double r, double i){
    return Math.sqrt(r*r+i*i);
}

public static void main(String[] args){


double a = modul(-2);
double b = modul(2,4);
System.out.println(a);
System.out.println(b);
}
}

