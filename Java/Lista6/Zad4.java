class Trojkat{
    protected double A;
    public Trojkat(double a){
        A = a;
    }
    public double Pole(){
        double pole = A*A*Math.sqrt(3)/4;
        System.out.printf("Pole rownobocznego: %f\n", pole);
        return pole;
    }
}

class TrojkatProstokatny extends Trojkat{
    double B;
    public TrojkatProstokatny(double a, double b){
        super(a);
        B = b;
    }

    public double Pole(){
        double pole = A*B/2;
        System.out.printf("Pole prostokatnego: %f\n", pole);
        return pole;
    }
}

class TrojkatRoznoboczny extends TrojkatProstokatny{
    double C;
    TrojkatRoznoboczny(double a, double b, double c){
        super(a,b);
        C = c;
    }

    public double Pole(){
        double p = (A+B+C)/2;
        double pole = Math.sqrt(p*(p-A)*(p-B)*(p-C));
         System.out.printf("Pole roznobocznego: %f\n", pole);
        return pole;
    }

}

public class Zad4 {
    public static void main(String[] args) {
        Trojkat a = new Trojkat(4);
        TrojkatProstokatny b = new TrojkatProstokatny(4, 5);
        TrojkatRoznoboczny c = new TrojkatRoznoboczny(3, 4, 6);
        a.Pole();
        b.Pole();
        c.Pole();
    }
}
