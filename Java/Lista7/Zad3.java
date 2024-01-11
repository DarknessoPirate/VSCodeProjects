import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
public class Zad3 {
    public static void main(String[] args) throws IOException {
        
        String file = "imiona2.txt";
        BufferedReader reader = new BufferedReader(new FileReader(file));
        ArrayList<String> list = new ArrayList<String>();
        String line;
        while((line = reader.readLine())!= null){
            list.add(line);
        }
        System.err.println(list);
        int size = list.size();
        String[] arr = list.toArray(new String[0]);
        
        for(int i = 0; i< size;i++){
            for(int j = 0; j<size-1;j++){
                if(arr[j].length() < arr[j+1].length()){
                    String temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
                // dokonczyc print i sort alfabetycznie
            }
        }
    }
    
}
