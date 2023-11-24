import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class Zad1 {
    
    static boolean isPrime(int number)
    {
        if (number < 1) return false;

        for(int i = 2; i <= number/2; i++)
        {
            if(number % i == 0) return false;
        }

        return true;
    }

    static void writePrimes(int numberOfPrimes, String path)
    {
        try {
            BufferedWriter myWriter = new BufferedWriter(new FileWriter("answer.txt", true));

            int counter =0;
            int i = 2;
            while(counter < numberOfPrimes)
            {
                i++;

                if(isPrime(i))
                {
                    myWriter.write(Integer.toString(i));
                    counter++;
                }

            }

        myWriter.close();
    }
    catch (IOException e)
    {
        e.printStackTrace();
    }
    }



    public static void main(String[] args) throws Exception
    {
        writePrimes(4, "answer.txt");
        System.out.println(isPrime(3));
        System.out.println(isPrime(4));
    }
}
