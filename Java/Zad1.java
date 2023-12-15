import java.util.Scanner;

public class Zad1 {
    public static int fibonacci(int n){
        if(n<=1){
            return n;
        }
        
        return fibonacci(n-1)+fibonacci(n-2);
    }

    static int findUnvenNumber(int number){
        int UnevenNumbersFound = 0;
        int UnevenNumber = 1;
        while(UnevenNumbersFound < number){
            if(UnevenNumber%2 == 1){
                ++UnevenNumbersFound;
                if(UnevenNumbersFound == number)
                    return UnevenNumber;
            }

                UnevenNumber++;

        }
        return UnevenNumber;
    }

    static void printMatrix(int[][] matrix,int size){
        for(int i = 0; i<size; i++){
            for(int j = 0 ; j<size; j++){
                System.out.printf("%d ", matrix[i][j]);
            }
            System.out.println();
        }
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Wybierz rozmiar macierzy:");
        int size = in.nextInt();
        int[][] macierz = new int[size][size];
        for(int i = 0; i<size;i++){
            for(int j = 0; j<size;j++){
                if(i == j){
                    macierz[i][j] = fibonacci(i+1);
                }
                if(j == 0){
                    macierz[i][j] = findUnvenNumber(i+1);
                }
            }
        }
        System.out.println("Utworzona macierz:");
        printMatrix(macierz, size);
    }
}
