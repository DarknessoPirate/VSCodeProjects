import java.io.*;
import java.util.Arrays;

public class Zad2 {
    
    static void insertionSort(int arr[], int n)
    {
        int key, j;
        for (int i = 1; i < n; i++) {
            key = arr[i];
            j = i - 1;
            
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }

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

    static void writeNumbersToFile(String path, int[] array) throws IOException
    {
        FileWriter myWriter = new FileWriter(path,true);
        for(int i = 0; i<array.length;i++)
        {
            String liczba = Integer.toString(array[i]);
            myWriter.write(liczba);
            myWriter.write(" ");
        }
        myWriter.close();


    }


    public static void main(String[] args) throws IOException
    {
        int[] numbers = new int[10];
        readNumbersFromFile("liczby.txt", numbers);
        insertionSort(numbers, numbers.length);
        writeNumbersToFile("liczbyposortowane.txt",numbers);
        System.out.println(Arrays.toString(numbers));

    }
}
