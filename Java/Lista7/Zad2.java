import java.io.File;

public class Zad2 {
    public static void main(String[] args) {
        String filePathString;
        File f = new File(filePathString);
        if(f.exists()) {   
            System.out.println("File exists!");
        }
        else{
            System.out.println("File doesn't exist");
        }
    }
}
