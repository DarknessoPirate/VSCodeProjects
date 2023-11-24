import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class Zad2 {
     static void readNamesFromFile(String path) throws IOException
    {
        BufferedReader myReader = new BufferedReader(new FileReader(path));
        String line;
        
       
        String[] buffer;
        Map<String,Integer> men = new HashMap();
        Map<String,Integer> women = new HashMap();
        while((line = myReader.readLine()) != null)
        {
            line.replaceAll("\\s+"," ");
            buffer = line.split(" ");
            System.out.println(lie);
        }
           // int last = buffer.length -1;
/* 
            if(buffer[last-1].equals("Mężczyzna"))
            {
                for(int i = last - 2; i>0 ; i--)
                {
                    if(men.containsKey(buffer[i]))
                    {
                        int temp = men.get(buffer[i]);
                        temp += Integer.parseInt(buffer[last]);
                        men.put(buffer[i],temp);
                    }

                    else{
                        int temp = Integer.parseInt(buffer[last]);
                        men.put(buffer[i],temp);
                    }


                }

            }

            else if(buffer[last -1].equals("Kobieta"))
            {
                 for(int i = last - 2; i>0 ; i--)
                {
                    if(women.containsKey(buffer[i]))
                    {
                        int temp = women.get(buffer[i]);
                        temp += Integer.parseInt(buffer[last]);
                        women.put(buffer[i],temp);
                    }

                    else{
                        int temp = Integer.parseInt(buffer[last]);
                        women.put(buffer[i],temp);
                    }
                }
            }
        }
        
        for (Map.Entry<String, Integer> e : men.entrySet()) 
  
            // Printing key-value pairs 
            System.out.println(e.getKey() + " "
                               + e.getValue()); 
                               */
    }

    public static void main(String[] args) throws IOException
    {
        readNamesFromFile("imiona.txt");





    }
    
}
