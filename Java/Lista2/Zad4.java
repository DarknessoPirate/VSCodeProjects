import java.util.*;

public class Zad4 
{
    public static void printArray(int[][] array)
    {
        for (int i = 0; i <array.length; i++)
        {
            System.out.println(Arrays.toString(array[i]));
        }
    }

    public static void fillArray(int[][] array, Scanner scanner)
    {
        
        for(int i = 0; i < array.length; i++)
        {
            for(int j = 0; j < array[i].length; j++)
            {
                System.out.println("[" + i + "]" +"["+ j + "]:");
                array[i][j] = scanner.nextInt();
            }
        }
        //cin.close(); <- nie dotykać

    }

    public static void CrossProduct(int[][] arrayA, int[][] arrayB) 
    {
        

        for(int i = 0 ;i< arrayA.length;i++)
        {
            for(int j = 0 ;j< arrayA.length ;j++)
            {
                int sum = 0;
                for(int k = 0 ;k< arrayA.length;k++)
                {
                    sum += arrayA[i][k] * arrayB[k][j];
                }
                
                System.out.print(sum);
            }
            System.out.println("");
        }

    }

    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        System.out.println("Array A size:");
        int a = in.nextInt();
        int b = a;
        int[][] arrayA = new int[a][a];
        int[][] arrayC = new int[b][b];

        fillArray(arrayA,in);
        printArray(arrayA);
        fillArray(arrayC,in);
        printArray(arrayC);

        CrossProduct(arrayA, arrayC);
        in.close();
    }

}
