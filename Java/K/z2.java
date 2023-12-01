
import java.util.regex.Pattern;
import java.util.regex.Matcher;

class person{
        private int age;
        private String name;
        private String PostCode;

        public person(int age1, String name1, String PostCode1){
            age = age1;
            name = name1;
            PostCode = PostCode1;
        }

        public boolean checkPostCode(){
            Pattern p = Pattern.compile("[0-9]{2}-[0-9]{3}");
            Matcher m = p.matcher(PostCode);
            return m.matches();
        }
    }
    
public class z2 {
    

    public static void main(String[] args) {
        person p1 = new person(1,"D", "44-110");
        System.out.println(p1.checkPostCode());
    }
}
