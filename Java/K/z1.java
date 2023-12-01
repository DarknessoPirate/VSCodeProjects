

public class z1{
    static int findEvenNumber(int number){
        int evenNumbersFound = 0;
        int evenNumber = 2;
        while(evenNumbersFound < number){
            if(evenNumber%2 == 0){
                ++evenNumbersFound;
                if(evenNumbersFound == number)
                    return evenNumber;
            }

                evenNumber++;

        }
        return evenNumber;
    }
    
    static boolean checkPrime(int number){
        if (number <= 1)
            return false;

        for(int i = 2; i<number;i++){
            if(number%i == 0){
                return false;
            }
        }
        return true;
    }
    static int findPrime(int number){
        int primesFound = 0;
        int primeNumber = 2;
        while(primesFound < number)
        {
            if(checkPrime(primeNumber)){
                ++primesFound;
                if(primesFound == number)
                    return primeNumber;
            }

                primeNumber++;

        }
        return primeNumber;
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
        String str = "cos dawno dawno temu dawno dawno temu 123";
        str = str.replaceAll("dawno dawno temu", "dawno DAWNO temu");
        System.out.println(str);
        int size = 4;
        int [][] macierz = new int[size][size];
        for(int i = 0; i<size;i++){
            for(int j = 0; j<size;j++){
                if(i == j){
                    macierz[i][j] = findPrime(i+1);
                }
                if(j == 0){
                    macierz[i][j] = findEvenNumber(i+1);
                }
            }
        }

        printMatrix(macierz, size);
    }




}