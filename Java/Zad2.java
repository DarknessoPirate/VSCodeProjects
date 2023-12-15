
public class Zad2 {
    public static int searchForIndex(String str, String substr, int number){
        int tempIndex = -1;
        int resultIndex = 0;
        for(int i = 0; i< number ; i++){
            tempIndex = str.indexOf(substr,resultIndex+1);
            if(tempIndex == -1){
                System.out.println("Nie znaleziono podciagu :(");
                return -1;
            }
            resultIndex = tempIndex;
        }
        System.out.println(resultIndex);
        return resultIndex;
    }
    public static void main(String[] args) {
        String tekst = "Leningi to bliscy, bliscy, bliscy, bliscy kuzyni chomików";
        String substr = "bliscy";
        int correctIndex = searchForIndex(tekst, substr, 3);
        int substrSize = substr.length();
        String newString = tekst.substring(0, correctIndex) + "BLISCY" + tekst.substring(correctIndex + substrSize);
        System.out.println(newString);

    }
}
