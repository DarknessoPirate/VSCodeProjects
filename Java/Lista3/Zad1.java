import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class Zad1 {

     static void readNumbersFromFile(String path, int[] array) throws IOException
    {
        BufferedReader myReader = new BufferedReader(new FileReader(path));
        String line;
        int k = 0;
        while ((line = myReader.readLine()) != null)
        {
            String[] splitString = line.split(",");
            
            for(int i = 0; i < splitString.length;i++,k++)
        {
            array[k] = Integer.parseInt(splitString[i]);
        }
        }
        myReader.close();
    }

    static int[] minMax(int[] array)
    {
        int min,max;
        int[] chuj = new int[2];
        min = array[0];
        max = array[0];
        for(int i = 0 ; i<array.length ; i++)
        {
            if(array[i]<min)
                min = array[i];

            if(array[i]>max)
                max = array[i];
        }
        chuj[0] = min;
        chuj[1] = max;
        return chuj;
    }

    static double[] srednie(int[] array)
    {
        double[] srednie = new double[3];
        double sum = 0;
        double product = 1;
        double denominator = 0;
        for(int i = 0 ; i<array.length; i++)
        {
            sum += array[i];
            product *= array[i];
            denominator += 1/array[i];
        }
        srednie[0] = sum/array.length;
        srednie[1] = Math.pow(product,1/array.length);
        srednie[2] = array.length/denominator;
        System.out.println(srednie[0] + "   " + srednie[1] + " " + srednie[2]);

        return srednie;
    }
    
    public static void main(String[] args) throws IOException
    {
        int [] array = new int[1000];
        readNumbersFromFile("dane.txt", array );
        int[] minMax = minMax(array);
        srednie(array);

    }



}
