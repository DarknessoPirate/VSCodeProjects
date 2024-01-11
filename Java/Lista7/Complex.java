


interface CInterface{
    public Complex Add(Complex other);
    public Complex Subtract(Complex other);
    public Complex Multiply(Complex other);
    public Complex Divide(Complex other);
    
};

public class Complex implements CInterface{
    double real;
    double imag;
    public Complex(double r, double i){
        this.real = r;
        this.imag = i;
    }
    public Complex Add(Complex other){

        return new Complex(this.real+other.real,this.imag+other.imag);
    }

    public Complex Subtract(Complex other){
        return new Complex(this.real-other.real,this.imag-other.imag);
    }
    public Complex Multiply(Complex other){
        double rea = this.real*other.real - this.imag*other.imag;
        double ima = this.real*other.imag + this.imag * other.real;
        return new Complex(rea,ima);
    }
    public Complex Divide(Complex other){
        double rea = (this.real+other.real + this.imag*other.imag)/(other.real*other.real+other.imag*other.imag);
        double ima = (this.imag*other.real - this.real*other.imag)/(other.real*other.real+other.imag*other.imag);
        return new Complex(rea,ima);
    }
}
