package space;


interface InnerR3{
    public R3 roznica(R3 other);
    public double dlugosc();
    public double iloczyn_skalarny(R3 other);
    public R3 iloczyn_wektorowy(R3 other);
}

public class R3 extends R2 implements InnerR3{
    public double x3;
    public R3(double a, double b, double c){
        super(a, b);
        this.x3 = c;
    }

    public R3 roznica(R3 other){
        return new R3(this.x1 - other.x1, this.x2 - other.x2, this.x3 - other.x3);
    }

    public double dlugosc(){
        return (Math.sqrt(this.x1*this.x1 + this.x2*this.x2 + this.x3*this.x3));
    }

    public double iloczyn_skalarny(R3 other){
        return (this.x1*other.x1 + this.x2*other.x2 + this.x3*other.x3);
    }

    public R3 iloczyn_wektorowy(R3 other){
        double a = this.x2 * other.x3 - this.x3*other.x2;
        double b = this.x3*other.x1 - this.x1*other.x3;
        double c = this.x1 * other.x2 - this.x2*other.x1;
        return new R3(a,b,c);
    }


}
