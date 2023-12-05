import java.util.Scanner;
import java.util.regex.Pattern;
import java.util.regex.Matcher;



class Osoba{
    private static int ID = 0;
    private String Imie;
    private String Nazwisko;
    private String Tel_kom;
    Pattern p1 = Pattern.compile("[0-9]{3}-?[0-9]{3}-?[0-9]{3}|[0-9]{3}\s[0-9]{3}\s[0-9]{3}");

    void inicjuj(){
        Scanner in = new Scanner(System.in);
        ++ID;
        System.out.println("Podaj imie: ");
        Imie = in.next();
        System.out.println("Podaj nazwisko: ");
        Nazwisko = in.next();
        System.out.println("Podaj telefon komorkowy: ");
        String temp = in.next();
        Matcher m = p1.matcher(temp);
        while(!m.matches()){
            System.out.println("Podaj telefon komorkowy: ");
            temp = in.nextLine();
            m = p1.matcher(temp);
        }
        Tel_kom = temp;
    }
    
    void wyswietl_dane(){
        System.out.printf("ID: %d\n", this.ID);
        System.out.printf("Imie: %s\n", this.Imie);
        System.out.printf("Nazwisko: %s\n", this.Nazwisko);
        System.out.printf("Telefon: %s\n",this.Tel_kom);
    }


}

public class Zad3 {
    int i = 1;
    public static void main(String[] args) {
        Osoba o1 = new Osoba();
        Osoba o2 = new Osoba();
        o1.inicjuj();
        o2.inicjuj();

        o1.wyswietl_dane();
        o2.wyswietl_dane();
    }
}
