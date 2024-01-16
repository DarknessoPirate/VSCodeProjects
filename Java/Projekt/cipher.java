
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.lang.Math;

public class cipher {


    static String convert_to_base(int number, int base){
        StringBuilder converted_number = new StringBuilder();
        while(number > 0){
            int temp = number % base;
            number /= base;
            converted_number.append(Integer.toString(temp));
        }
        converted_number.reverse();
        return converted_number.toString();
    }

    static int convert_to_decimal(String number, int base){
        String[] numberArr = number.split("");
        int number_index = 0;
        int result = 0;
        for(int i = numberArr.length-1; i >= 0; i--){
            int current_number = Integer.parseInt(numberArr[i]);
            if(number_index == 0){
                result += current_number;
            }
            else{
                result += current_number*Math.pow(base, number_index);
            }
            number_index++;
        }
        return result;
    }

    static String convert_to_ascii(String word){
        String result = "";
        for(int i = 0 ; i<word.length();i++){
            result += Integer.toString((int)word.charAt(i));
            result += " ";
        }
        return result;
    }

    static String cipher_word(String word){
        int current_letter = 0;
        String result = "";
        String str_buffer = "";
        int int_buffer = 0;
        String text = convert_to_ascii(word);
        int i = 0;
        int base;
        while(i< text.length()){
            while(text.charAt(i) != ' '){
                str_buffer += text.charAt(i);
                i++;
            }
            
            if(current_letter == 0){
                int_buffer = Integer.parseInt(str_buffer);
                result += convert_to_base(int_buffer, 2);
                result += " ";
            }
            else{
                base = int_buffer % 8 + 2;
                int_buffer = Integer.parseInt(str_buffer);
                result += convert_to_base(int_buffer, base);
                result += " ";
            }
            current_letter++;
            i++;
            str_buffer = "";
        }
        return result;
    }

    static String decipher_word(String word){
        String result = "";
        String str_buffer = "";
        int current_letter = 0;
        int int_buffer = 0;
        int base;
        int i = 0;
        while(i < word.length()){
            while(word.charAt(i) != ' '){
                str_buffer += word.charAt(i);
                i++;
            }
            if(current_letter == 0){
                int_buffer = convert_to_decimal(str_buffer, 2);
                result += (char)int_buffer;
            }
            else{
                base = int_buffer % 8 + 2;
                int_buffer = convert_to_decimal(str_buffer, base);
                result += (char)int_buffer;
            }
            current_letter++;
            i++;
            str_buffer = "";
        }
        return result;
    }

    static String readDataFromFile(String path) throws IOException
    {
        BufferedReader myReader = new BufferedReader(new FileReader(path));
        String line;
        int k = 0;
        while ((line = myReader.readLine()) != null)
        {
            String[] splitString = line.split(" ");
            
            for(int i = 0; i < splitString.length;i++,k++)
        {
            System.out.printf("%s ",splitString[i]);
        }
        }
        myReader.close();
        return "0";//////////////////////////////
    }

    static void cipher_to_file(String path_from, String path_to) throws IOException{
        BufferedReader myReader = new BufferedReader(new FileReader(path_from));
        BufferedWriter myWriter = new BufferedWriter(new FileWriter(path_to));
        String current_ciphered_word;
        String line;

        while ((line = myReader.readLine()) != null){
            String[] words = line.split(" ");
    
            for(int i = 0; i < words.length;i++){
                current_ciphered_word = cipher_word(words[i]);
                myWriter.append(current_ciphered_word);
                myWriter.append('\n');
            }
        }
        myReader.close();
        myWriter.close();
    }

    static void decipher_from_file(String path_from,String path_to) throws IOException{
        BufferedReader myReader = new BufferedReader(new FileReader(path_from));
        BufferedWriter myWriter = new BufferedWriter(new FileWriter(path_to, true));
        String current_deciphered_word;
        String line;

        while ((line = myReader.readLine()) != null){
            current_deciphered_word = decipher_word(line);
            myWriter.append(current_deciphered_word);
            myWriter.append(' ');
        }
        myReader.close();
        myWriter.close();
    }

    public static void main(String[] args) throws IOException{
        cipher_to_file("normal_text.txt", "ciphered_text.txt");
        decipher_from_file("ciphered_text.txt", "deciphered_text.txt");
    }
}
