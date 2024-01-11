package space;
import java.lang.Math;
interface InnerR2 {
    public R2 roznica(R2 other);
    public double dlugosc();
    public double iloczyn_skalarny(R2 other);
}

public class R2 implements InnerR2{
    public double x1;
    public double x2;
    public R2(double a,double b){
        this.x1 = a;
        this.x2 = b;
    }
    public R2 roznica(R2 other){
        return new R2(this.x1 - other.x1, this.x2 - other.x2);
    }

    public double dlugosc(){
        return (Math.sqrt(this.x1*this.x1 + this.x2*this.x2));
    }

    public double iloczyn_skalarny(R2 other){
        return (this.x1*other.x1 + this.x2*other.x2);
    }
}
