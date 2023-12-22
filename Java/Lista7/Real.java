



public interface Interface{
    public double Add(Real other);
    public double Subtract(Real other);
    public double Multiply(Real other);
    public double Divide(Real other);
    
};

public class Real implements Interface{
    public double real;

    public Real(double r){
        real = r;
    }

    public double Add(Real other){
        return this.real + other.real;
    }

    public double Subtract(Real other){
        return this.real - other.real;
    }

    public double Multiply(Real other){
        return this.real * other.real;
    }

    public double Divide(Real other){
        return this.real/other.real;
    }
}