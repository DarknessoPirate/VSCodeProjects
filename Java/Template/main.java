import space.R2;
import space.R3;

public class main {
    public static void main(String[] args) {
        R2 vec21 = new R2(2.0,2.0);
        R2 vec22 = new R2(1.0,1.0);
        System.out.println(vec21.dlugosc());
        System.out.println(vec21.roznica(vec22).x1);
        R3 vec31 = new R3(2.0,2.0,2.0);
        R3 vec32 = new R3(2.0,2.0,3.0);
        System.out.println(vec31.iloczyn_skalarny(vec32));
    }
}
