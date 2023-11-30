public class Zad3 {
    
    public static int fibonacci(int n){
        if(n==0){
            return 1;
        }
        
        return n*fibonacci(n-1);
    }

    public static void main(String[] args){
        System.out.println(fibonacci(5));
        int sum = 0;
        for(int i = 1;i<6;i++){
            System.out.println(fibonacci(i));
            sum+=fibonacci(i);
        }
        System.out.println(sum);
    }


}
