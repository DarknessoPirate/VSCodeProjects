
import java.io.*;
import java.util.*;

public class Zad3 {
    
    public static void fillArray(int[][] array) 
    {
        int value = 1;
        

        for(int i = 0; i<array.length; i++)
        {
            for(int j = 0; j<array[i].length;j++)
            {
                if(i==j) array[i][j] = i+1;
                else if(i==j-1) array[i][j] = value++;
                else if(i==j+1)  array[i][j] = value++;
            }
        }
    }

    public static void writeArray(int[][] array, String path) throws IOException
    {
        String buffer;
        FileWriter myWriter = new FileWriter(path,true);
        for(int i=0; i<array.length; i++)
        {
            buffer = Arrays.toString(array[i]);
            myWriter.write(buffer);
            myWriter.write("\n");
        }
        myWriter.close();
    }

    public static void main(String[] args) throws IOException
    {
        Scanner cin = new Scanner(System.in);
        System.out.println("Array size:");
        int n = cin.nextInt();
        int[][] array = new int[n][n];

        fillArray(array);
        for (int i = 0; i <array.length; i++)
        {
            System.out.println(Arrays.toString(array[i]));
        }

        writeArray(array, "matrix.txt");
        //cnd
        
    }
}
